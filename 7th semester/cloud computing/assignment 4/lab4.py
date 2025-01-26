import random
import matplotlib.pyplot as plt

class Processor:
    def __init__(self, serviceRate, queueSize, name):
        self.serviceRate = serviceRate
        self.queueSize = queueSize
        self.name = name
        self.queue = []
        self.served = 0
        self.dropped = 0
        self.busyUntil = 0
        self.waitingTime = 0
        self.wasFree = True
        self.totalBusyTime = 0


    def isFree(self, currentTime):
        return self.busyUntil <= currentTime


    def addTask(self, currentTime):
        if len(self.queue) < self.queueSize:
            self.queue.append(currentTime)
        else:
            self.dropped += 1


    def tick(self, currentTime):
        served = False

        if self.isFree(currentTime):
            if not self.wasFree:
                self.served += 1
                self.waitingTime += currentTime - self.queue.pop(0)
                self.wasFree = True
                served = True

            if self.queue:
                self.busyUntil = currentTime + random.expovariate(self.serviceRate)
                self.totalBusyTime += self.busyUntil - currentTime
                self.wasFree = False
        
        return served


    def getStatus(self):
        status = {
            "name": self.name,
            "total": self.served + self.dropped + len(self.queue),
            "served": self.served,
            "dropped": self.dropped,
            "queue": len(self.queue),
            "waitingTime": self.waitingTime,
            "totalBusyTime": self.totalBusyTime
        }

        return status



class LoadBalancer:
    def __init__(self, arrivalRate, processors, simulationTime):
        self.arrivalRate = arrivalRate
        self.processors = []
        self.processorWeights = []
        self.simulationTime = simulationTime
        self.assignmentFunc = None
        self.assignmentVars = {}
        self.arrivalsInTime = {}
        self.departuresInTime = {}

        for i, processor in enumerate(processors):
            self.processors.append(Processor(processor[0], processor[1], i))
            
            if len(processor) == 2:
                self.assignmentFunc = self.roundRobin

            elif len(processor) > 2:
                self.processorWeights.append(processor[2])
                self.assignmentFunc = self.weightedRoundRobin

        self.start()


    def start(self):
        currentTime = random.expovariate(self.arrivalRate)

        while currentTime < self.simulationTime:
            self.arrivalsInTime[currentTime] = self.arrivalsInTime.get("last", 0) + 1
            self.arrivalsInTime["last"] = self.arrivalsInTime[currentTime]

            nextProcessor = self.assignmentFunc()
            self.processors[nextProcessor].addTask(currentTime)

            for processor in self.processors:
                if processor.tick(currentTime):
                    self.departuresInTime[currentTime] = self.departuresInTime.get("last", 0) + 1
                    self.departuresInTime["last"] = self.departuresInTime[currentTime]

            currentTime += random.expovariate(self.arrivalRate)

        del self.arrivalsInTime["last"]
        del self.departuresInTime["last"]

        self.stats()
        self.plotArrivals()


    def stats(self):
        totalTasks = 0
        totalServed = 0
        totalDropped = 0
        totalLeftInQueue = 0
        totalWaitingTime = 0

        for processor in self.processors:
            status = processor.getStatus()

            totalTasks += status["total"]
            totalServed += status["served"]
            totalDropped += status["dropped"]
            totalLeftInQueue += status["queue"]
            totalWaitingTime += status["waitingTime"]

            print(f"Processor {status["name"]}:")
            print(f"    Total tasks: {status["total"]}")
            print(f"    Served tasks: {status["served"]}")
            print(f"    Dropped tasks: {status["dropped"]} ({round(status["dropped"] / status["total"] * 100, 2)}%)")
            print(f"    Tasks left in queue: {status["queue"]}")
            print(f"    Average waiting time: {round(status["waitingTime"] / status["served"], 2)}")
            print(f"    Total busy time: {round(status["totalBusyTime"] / self.simulationTime * 100, 2)}%")
            print("\n\n")

        print(f"Total tasks: {totalTasks}")
        print(f"Total served: {totalServed}")
        print(f"Total dropped: {totalDropped} ({round(totalDropped / totalTasks * 100, 2)}%)")
        print(f"Total left in queue: {totalLeftInQueue}")
        print(f"Total average waiting time: {round(totalWaitingTime / totalServed, 2)}")


    def roundRobin(self):
        if not self.assignmentVars:
            self.assignmentVars["next"] = 0

            return self.assignmentVars["next"]
        
        self.assignmentVars["next"] = (self.assignmentVars["next"] + 1) % len(self.processors)

        return self.assignmentVars["next"]


    def weightedRoundRobin(self):
        if not self.assignmentVars:
            for i in range(len(self.processors)):
                self.assignmentVars[i] = 0
            
            self.assignmentVars["next"] = 0
        
        if self.assignmentVars[self.assignmentVars["next"]] < self.processorWeights[self.assignmentVars["next"]]:
            self.assignmentVars[self.assignmentVars["next"]] += 1

            return self.assignmentVars["next"]
        
        self.assignmentVars[self.assignmentVars["next"]] = 0
        self.assignmentVars["next"] = (self.assignmentVars["next"] + 1) % len(self.processors)
        self.assignmentVars[self.assignmentVars["next"]] += 1

        return self.assignmentVars["next"]


    def plotArrivals(self):
        plt.plot(list(self.arrivalsInTime.keys()), list(self.arrivalsInTime.values()), label="Arrivals")
        plt.plot(list(self.departuresInTime.keys()), list(self.departuresInTime.values()), label="Departures")
        plt.legend()
        plt.show()



if __name__ == "__main__":
    # processors = [
    #     (1, 10),
    #     (1, 10),
    #     (1, 10),
    #     (1, 10)
    # ]

    processors = [
        (1, 10, 3),
        (1, 10, 4),
        (1, 10, 2),
        (1, 10, 1)
    ]
    
    # processors = [
    #     (5, 10, 3),
    #     (7, 10, 4),
    #     (4, 10, 2),
    #     (2, 10, 1)
    # ]

    LoadBalancer(5, processors, 1000)