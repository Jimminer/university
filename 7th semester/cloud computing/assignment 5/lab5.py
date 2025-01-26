import random
import threading
import matplotlib.pyplot as plt
import time

DEBUG = False

tasks = []
tasksLock = threading.Lock()

processorInfo = {}
processorInfoLock = threading.Lock()

simulationActive = threading.Event()
simulationActive.set()

departuresInTime = {}
departuresInTimeLock = threading.Lock()

currentTime = 0

taskDistribution = {
    "eMBB": 0.3,
    "IoT": 0.6,
    "URLLC": 0.1
}
# convert from requests per hour to requests per millisecond
taskArrival = {
    "eMBB": 2/(60 * 60 * 1000),
    "IoT": 120/(60 * 60 * 1000),
    "URLLC": 1/(60 * 60 * 1000)
}
taskLatency = {
    "eMBB": {"CPU": 57, "GPU": 1.6, "FPGA": 35},
    "IoT": {"CPU": 20.3, "GPU": 0.5, "FPGA": 1.8},
    "URLLC": {"CPU": 25, "GPU": 0.02, "FPGA": 3.3}
}
taskLatencyDeviation = {
    "eMBB": {"CPU": 10, "GPU": 0.1, "FPGA": 4},
    "IoT": {"CPU": 3, "GPU": 0.05, "FPGA": 0.2},
    "URLLC": {"CPU": 2, "GPU": 0.0001, "FPGA": 0.3}
}
taskPower = {
    "eMBB": {"CPU": 15.4, "GPU": 26.9, "FPGA": 12.5},
    "IoT": {"CPU": 23.5, "GPU": 28.4, "FPGA": 15.3},
    "URLLC": {"CPU": 21.6, "GPU": 26, "FPGA": 12.5}
}



class Datacenter:
    def __init__(self, serverCount, processors, requestCount, queueSize):
        self.serverCount = serverCount
        self.processors = processors
        self.requestCount = requestCount
        self.queueSize = queueSize
        
        # integer division (removes remainder)
        self.requestCountPerServer = requestCount // serverCount
        self.servers = []

        self.createServers()

    def createServers(self):
        for i in range(self.serverCount):
            serverProcessors = []
            processorInfo[i] = {}
            departuresInTime[i] = {}
            departuresInTime[i]["last"] = 0

            for j, processor in enumerate(self.processors):
                processor = Processor(j, i, processor, self.queueSize)
                serverProcessors.append(processor)

            server = Server(i, serverProcessors, self.requestCountPerServer, self.queueSize)
            serverActive = threading.Event()
            serverActive.set()
            removedTasks = []
            thread = threading.Thread(target=server.start, args=[serverActive, removedTasks])

            self.servers.append((server, thread, serverActive, removedTasks))
    
    def start(self):
        for server, thread, _, _ in self.servers:
            thread.start()

        threading.Thread(target=self.printInfo).start()

        skipEnabled = False
        timeSkip = None
        previouslySkipped = False
        skip = False

        while True:
            global currentTime
     
            minimumArrivalTime = float("inf")

            if all(server.requestsLeft <= 0 for server, _, _, _ in self.servers):
                skipEnabled = True

            if previouslySkipped:
                if timeSkip.departureTime:
                    previouslySkipped = False
            elif skipEnabled:
                with tasksLock:
                    for task in tasks:
                        if not task.arrivalTime < minimumArrivalTime:
                            continue

                        minimumArrivalTime = task.arrivalTime
                        timeSkip = task
                        skip = True
            
            if skip:
                currentTime = minimumArrivalTime - 30000
                skip = False
                previouslySkipped = True
            else:
                currentTime += 10000

            if not any(serverActive.is_set() for _, _, serverActive, _ in self.servers):
                break

            time.sleep(0.00001)

        simulationActive.clear()

        for _, thread, _, _ in self.servers:
            thread.join()
    
    def printInfo(self):
        lines = 4
        UP = f"\x1B[{lines}A"
        CLR = "\x1B[0K"
        print("\n" * lines, end="")
        global currentTime

        while simulationActive.is_set():

            print(f"{UP}Current time: {round(currentTime, 2)}          {CLR}")
            with tasksLock:
                print(f"Unprocessed tasks: {len(tasks)}          {CLR}")
            print(f"Requests left: {max(sum(server.requestsLeft for server, _, _, _ in self.servers), 0)}          {CLR}")
            print(f"Tasks left in queue: {sum(info["queueSize"] for processors in processorInfo.values() for _, info in processors.items())}          {CLR}")

            time.sleep(0.5)

    def stats(self):
        overallStats = {
            "totalTasks": 0,
            "totalServed": 0,
            "totalDropped": 0,
            "totalWaitingTime": 0,
            "totalPower": 0,
            "totalTaskCounts": {
                "eMBB": 0,
                "IoT": 0,
                "URLLC": 0
            }
        }
        for server, _, _, _ in self.servers:
            collectedStats = server.stats()

            overallStats["totalTasks"] += collectedStats["totalTasks"]
            overallStats["totalServed"] += collectedStats["totalServed"]
            overallStats["totalDropped"] += collectedStats["totalDropped"]
            overallStats["totalWaitingTime"] += collectedStats["totalWaitingTime"]
            overallStats["totalPower"] += collectedStats["totalPower"]

            for taskType, count in collectedStats["totalTaskCounts"].items():
                overallStats["totalTaskCounts"][taskType] += count
        
        print(f"Overall stats:")
        print()
        
        print(f"Overall tasks: {overallStats["totalTasks"]}")
        print(f"Overall served: {overallStats["totalServed"]}")
        if overallStats["totalTasks"] > 0:
            print(f"Overall dropped: {overallStats["totalDropped"]} ({round(overallStats["totalDropped"] / overallStats["totalTasks"] * 100, 2)}%)")
        else:
            print(f"Overall dropped: 0 (0%)")
        print(f"Overall average waiting time: {round(overallStats["totalWaitingTime"] / overallStats["totalServed"] / 1000, 2)} seconds")
        print(f"Overall power consumption: {round(overallStats["totalPower"], 2)} W")
        print(f"Overall task type counts:")

        for taskType, count in overallStats["totalTaskCounts"].items():
            print(f"    {taskType}: {count}")

    
    def plotInfo(self):
        arrivalsInTime = {}
        departuresInTime = {}
        droppedInTime = {}

        for server, _, _, removedTasks in self.servers:
            arrivalsInTime[server.id] = {
                "All": {},
                "eMBB": {},
                "IoT": {},
                "URLLC": {}
            }

            departuresInTime[server.id] = {
                "All": {},
                "eMBB": {},
                "IoT": {},
                "URLLC": {}
            }
           
            droppedInTime[server.id] = {
                "All": {},
                "eMBB": {},
                "IoT": {},
                "URLLC": {}
            }

            removedTasks.sort(key=lambda x: x.arrivalTime)

            for task in removedTasks:
                arrivalsInTime[server.id]["All"][task.arrivalTime] = arrivalsInTime[server.id]["All"].get("last", 0) + 1
                arrivalsInTime[server.id][task.taskType][task.arrivalTime] = arrivalsInTime[server.id][task.taskType].get("last", 0) + 1
                arrivalsInTime[server.id]["All"]["last"] = arrivalsInTime[server.id]["All"][task.arrivalTime]
                arrivalsInTime[server.id][task.taskType]["last"] = arrivalsInTime[server.id][task.taskType][task.arrivalTime]

            for task in removedTasks:
                if not task.departureTime:
                    droppedInTime[server.id]["All"][task.arrivalTime] = droppedInTime[server.id]["All"].get("last", 0) + 1
                    droppedInTime[server.id][task.taskType][task.arrivalTime] = droppedInTime[server.id][task.taskType].get("last", 0) + 1
                    droppedInTime[server.id]["All"]["last"] = droppedInTime[server.id]["All"][task.arrivalTime]
                    droppedInTime[server.id][task.taskType]["last"] = droppedInTime[server.id][task.taskType][task.arrivalTime]

            removedTasks = [task for task in removedTasks if task.departureTime]
            removedTasks.sort(key=lambda x: x.departureTime)

            for task in removedTasks:
                departuresInTime[server.id]["All"][task.departureTime] = departuresInTime[server.id]["All"].get("last", 0) + 1
                departuresInTime[server.id][task.taskType][task.departureTime] = departuresInTime[server.id][task.taskType].get("last", 0) + 1
                departuresInTime[server.id]["All"]["last"] = departuresInTime[server.id]["All"][task.departureTime]
                departuresInTime[server.id][task.taskType]["last"] = departuresInTime[server.id][task.taskType][task.departureTime]

        fig, axs = plt.subplots(3, 4, figsize=(20, 13))

        for serverId, arrivals in arrivalsInTime.items():
            for i, (taskType, taskArrivals) in enumerate(arrivals.items()):
                taskArrivals.pop("last", None)
                hours = [time / (1000 * 60 * 60) for time in taskArrivals.keys()]
                axs[0, i].plot(hours, taskArrivals.values(), label=f"Server {serverId} {taskType} arrivals")
                axs[0, i].set_title(f"{taskType} Task Arrivals Over Time")
                axs[0, i].set_xlabel("Time (hours)")
                axs[0, i].set_ylabel("Number of Arrivals")
                axs[0, i].legend()
                axs[0, i].grid()
        
        for serverId, departures in departuresInTime.items():
            for i, (taskType, taskDepartures) in enumerate(departures.items()):
                taskDepartures.pop("last", None)
                hours = [time / (1000 * 60 * 60) for time in taskDepartures.keys()]
                axs[1, i].plot(hours, taskDepartures.values(), label=f"Server {serverId} {taskType} departures")
                axs[1, i].set_title(f"{taskType} Task Departures Over Time")
                axs[1, i].set_xlabel("Time (hours)")
                axs[1, i].set_ylabel("Number of Departures")
                axs[1, i].legend()
                axs[1, i].grid()

        for serverId, dropped in droppedInTime.items():
            for i, (taskType, taskDropped) in enumerate(dropped.items()):
                taskDropped.pop("last", None)
                hours = [time / (1000 * 60 * 60) for time in taskDropped.keys()]
                axs[2, i].plot(hours, taskDropped.values(), label=f"Server {serverId} {taskType} dropped")
                axs[2, i].set_title(f"{taskType} Tasks Dropped Over Time")
                axs[2, i].set_xlabel("Time (hours)")
                axs[2, i].set_ylabel("Number of Dropped Tasks")
                axs[2, i].legend()
                axs[2, i].grid()
        
        plt.tight_layout()
        plt.show()



class Server:
    def __init__(self, id, processors, requestCount, queueSize):
        self.id = id
        self.processors = processors
        self.requestCount = requestCount
        self.queueSize = queueSize

        self.threads = []
        self.taskTimes = {
            "eMBB": 0,
            "IoT": 0,
            "URLLC": 0
        }
        self.requestsLeft = requestCount

    def generateTask(self):
        taskType = random.choices(list(taskDistribution.keys()), list(taskDistribution.values()))[0]
        
        previousTaskTime = self.taskTimes[taskType]

        taskTime = previousTaskTime + random.expovariate(taskArrival[taskType])

        self.taskTimes[taskType] = taskTime

        if taskType == "URLLC":
            for i in range(20):
                task = Task(taskType, taskTime)

                task.setProcessor(self.id, random.choice(self.processors).id)

                with tasksLock:
                    tasks.append(task)

                self.requestsLeft -= 1
            
            return
        
        task = Task(taskType, taskTime)
        self.loadBalancer(task)

        with tasksLock:
            tasks.append(task)

        self.requestsLeft -= 1

        if DEBUG:
            print()
            print(f"Task {taskType} generated at {taskTime} for processor {self.id}-{task.processorId} (current time: {currentTime})")
            print()

    def start(self, serverActive, removedTasks):
        removedTasksLock = threading.Lock()

        for processor in self.processors:
            thread = threading.Thread(target=processor.start, args=[serverActive, removedTasks, removedTasksLock])
            self.threads.append(thread)
            thread.start()
        
        while True:
            if DEBUG:
                print()
                print(f"Current time: {currentTime} | Requests left: {self.requestsLeft} | Unprocessed tasks: {len(tasks)}")
                print()

            if not tasks and self.requestsLeft <= 0:
                processorBusy = False

                for serverId, processors in processorInfo.items():
                    for processorId, info in processors.items():
                        if info["queueSize"] > 0:
                            processorBusy = True
                            break

                    if processorBusy:
                        break

                if not processorBusy:
                    break

            if self.requestsLeft > 0:
                self.generateTask()
            
        
        # signal all processors to stop
        serverActive.clear()
        for thread in self.threads:
            thread.join()
    
    def loadBalancer(self, task):
        processorRanking = []

        for processor in self.processors:
            latency = taskLatency[task.taskType][processor.processorType]
            power = taskPower[task.taskType][processor.processorType]
            queueSize = processorInfo[self.id][processor.id]["queueSize"]
            efficiency = latency / power
            processorRanking.append((processor, efficiency, queueSize))

        # rank processors first by queue size and then by efficiency (latency/power)
        processorRanking.sort(key=lambda x: (x[2], x[1]))

        for processor, _, queueSize in processorRanking:
            if queueSize < self.queueSize:
                task.setProcessor(self.id, processor.id)
                return
        
        task.setProcessor(self.id, random.choice(processorRanking)[0].id)

    def stats(self):
        print("\n\n-----------------------------------------------\n\n")

        totalTasks = 0
        totalServed = 0
        totalDropped = 0
        totalWaitingTime = 0
        totalPower = 0
        totalTaskCounts = {
            "eMBB": 0,
            "IoT": 0,
            "URLLC": 0
        }

        for processor in self.processors:
            status = processor.getStatus()

            totalTasks += status["total"]
            totalServed += status["served"]
            totalDropped += status["dropped"]
            totalWaitingTime += status["waitingTime"]
            totalPower += status["totalPowerConsumption"]

            print(f"Processor {status["id"]} ({status["processorType"]}):")
            print(f"    Received tasks: {status["total"]}")
            print(f"    Served tasks: {status["served"]}")
            if status["total"] > 0:
                print(f"    Dropped tasks: {status["dropped"]} ({round(status["dropped"] / status["total"] * 100, 2)}%)")
            else:
                print(f"    Dropped tasks: 0 (0%)")
            if status["served"] > 0:
                print(f"    Average waiting time: {round(status["waitingTime"] / status["served"] / 1000, 2)} seconds")
            else:
                print(f"    Average waiting time: 0 seconds")
            print(f"    Utilization: {round(status["totalBusyTime"] / currentTime * 100, 2)}%")
            print(f"    Power consumption: {round(status["totalPowerConsumption"], 2)} W")
            print(f"    Task type counts:")
            for taskType, count in status["taskCounts"].items():
                print(f"        {taskType}: {count}")
                totalTaskCounts[taskType] += count
            print("\n")

        print(f"Server {self.id} total stats:")
        print(f"    Total received tasks: {totalTasks}")
        print(f"    Total served: {totalServed}")
        if totalTasks > 0:
            print(f"    Total dropped: {totalDropped} ({round(totalDropped / totalTasks * 100, 2)}%)")
        else:
            print(f"    Total dropped: 0 (0%)")
        if totalServed > 0:
            print(f"    Total average waiting time: {round(totalWaitingTime / totalServed / 1000, 2)} seconds") 
        else:
            print(f"    Total average waiting time: 0")
        print(f"    Total power consumption: {round(totalPower, 2)} W")
        print(f"    Total task type counts:")
        for taskType, count in totalTaskCounts.items():
            print(f"    {taskType}: {count}")
        
        print("\n\n-----------------------------------------------\n\n")

        return {
            "totalTasks": totalTasks,
            "totalServed": totalServed,
            "totalDropped": totalDropped,
            "totalWaitingTime": totalWaitingTime,
            "totalPower": totalPower,
            "totalTaskCounts": totalTaskCounts
        }



class Processor:
    def __init__(self, id, serverId, processorType, queueSize):
        self.id = id
        self.serverId = serverId
        self.processorType = processorType
        self.queueSize = queueSize

        self.queue = []
        self.served = 0
        self.dropped = 0
        self.wasFree = True
        self.busyUntil = 0
        self.waitingTime = 0
        self.totalBusyTime = 0
        self.totalPowerConsumption = 0
        self.taskCounts = {
            "eMBB": 0,
            "IoT": 0,
            "URLLC": 0
        }
        with processorInfoLock:
            processorInfo[self.serverId][self.id] = {
                "processorType": self.processorType,
                "queueSize": len(self.queue)
            }
    
    def isFree(self, currentTime):
        return self.busyUntil <= currentTime

    def updateProcessorInfo(self):
        with processorInfoLock:
            processorInfo[self.serverId][self.id]["queueSize"] = len(self.queue)

    def start(self, serverActive, removedTasks, removedTasksLock):
        while serverActive.is_set():
            global currentTime
            curTime = currentTime

            with tasksLock:
                for task in tasks:
                    if task.serverId == self.serverId and task.processorId == self.id and task.arrivalTime <= curTime:
                        if len(self.queue) < self.queueSize:
                            self.queue.append(task)
                            self.updateProcessorInfo()
                        else:
                            self.dropped += 1

                        self.taskCounts[task.taskType] += 1
                        
                        tasks.remove(task)

                        with removedTasksLock:
                            removedTasks.append(task)


            if not self.isFree(curTime):
                continue

            if not self.queue:
                continue
                
            if not self.wasFree:
                task = self.queue.pop(0)
                self.updateProcessorInfo()
                self.served += 1
                self.waitingTime += curTime - task.arrivalTime
                self.wasFree = True
                task.setDepartureTime(curTime)
            
            if not self.queue:
                continue

            self.queue.sort(key=lambda x: x.arrivalTime)
            task = self.queue[0]
            deviation = taskLatencyDeviation[task.taskType][self.processorType]
            self.busyUntil = curTime + taskLatency[task.taskType][self.processorType] + random.uniform(-deviation, deviation)
            self.totalBusyTime += self.busyUntil - curTime
            self.totalPowerConsumption += taskPower[task.taskType][self.processorType]
            self.wasFree = False
    
    def getStatus(self):
        return {
            "id": self.id,
            "processorType": self.processorType,
            "total": self.served + self.dropped + len(self.queue),
            "served": self.served,
            "dropped": self.dropped,
            "queue": len(self.queue),
            "waitingTime": self.waitingTime,
            "totalBusyTime": self.totalBusyTime,
            "totalPowerConsumption": self.totalPowerConsumption,
            "taskCounts": self.taskCounts
        }



class Task:
    def __init__(self, taskType, arrivalTime):
        self.taskType = taskType
        self.arrivalTime = arrivalTime

        self.departureTime = None
        self.serverId = None
        self.processorId = None
    
    def setProcessor(self, serverId, processorId):
        self.serverId = serverId
        self.processorId = processorId

    def setDepartureTime(self, departureTime):
        self.departureTime = departureTime



if __name__ == "__main__":
    serverCount = 7
    processors = ["CPU", "GPU", "FPGA"]
    requestCount = 10000
    queueSize = 10

    datacenter = Datacenter(serverCount, processors, requestCount, queueSize)
    datacenter.start()
    datacenter.stats()
    datacenter.plotInfo()