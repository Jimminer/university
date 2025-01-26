# Cloud Computing: Load balancing Lab 3
# Distribute requests among 2 processors each with a separate queue
# Requests arrive at a rate of 5 per second in an exponential distribution and are served at a rate of 6 per second (each processor can process independently). Each queue can hold up to 10 requests. Simulate for 1000 seconds.
# The needed output is:
#   1. Average waiting time in the queue
#   2. Total number of arrivals
#   3. Total number of departures
#   4. Total number of requests served by each processor
#   5. Average utilization of each processor
#   6. Number of dropped requests

import random

arrivalRate = 5
serviceRate = 6
queueSize = 10
simulationTime = 1000

queue1 = []
queue2 = []
p1BusyUntilTime = float('inf')
p2BusyUntilTime = float('inf')
totalArrivals = 0
totalDepartures = 0
droppedByP1 = 0
droppedByP2 = 0
totalDroppedRequests = 0
totalServedByP1 = 0
totalServedByP2 = 0
totalWaitTime = 0

currentTime = 0
nextArrival = random.expovariate(arrivalRate)

while currentTime < simulationTime:
    currentTime = nextArrival

    if p1BusyUntilTime <= currentTime:
        p1BusyUntilTime = float('inf')
        totalServedByP1 += 1
        totalDepartures += 1
    
    if p2BusyUntilTime <= currentTime:
        p2BusyUntilTime = float('inf')
        totalServedByP2 += 1
        totalDepartures += 1

    if currentTime == nextArrival:
        totalArrivals += 1

        if p1BusyUntilTime < p2BusyUntilTime:
            if len(queue1) < queueSize:
                queue1.append(currentTime)
            
            else:
                droppedByP1 += 1
        
        elif p2BusyUntilTime < p1BusyUntilTime:
            if len(queue2) < queueSize:
                queue2.append(currentTime)
            
            else:
                droppedByP2 += 1

        else:
            if len(queue1) < len(queue2):
                if len(queue1) < queueSize:
                    queue1.append(currentTime)
                
                else:
                    droppedByP1 += 1
            
            else:
                if len(queue2) < queueSize:
                    queue2.append(currentTime)
                
                else:
                    droppedByP2 += 1

        nextArrival = currentTime + random.expovariate(arrivalRate)

    if queue1:
        if p1BusyUntilTime == float('inf'):
            p1BusyUntilTime = currentTime + random.expovariate(serviceRate)
            totalWaitTime += currentTime - queue1.pop(0)

    if queue2:
        if p2BusyUntilTime == float('inf'):
            p2BusyUntilTime = currentTime + random.expovariate(serviceRate)
            totalWaitTime += currentTime - queue2.pop(0)
        
totalDroppedRequests = droppedByP1 + droppedByP2

print(f"Average waiting time in the queue: {round(totalWaitTime / totalDepartures, 2)}")
print(f"Total number of arrivals: {totalArrivals}")
print(f"Total number of departures: {totalDepartures}")
print("Total number of requests served by each processor:")
print(f"  Processor 1: {totalServedByP1}")
print(f"  Processor 2: {totalServedByP2}")
print("Average utilization of each processor:")
print(f"  Processor 1: {round(totalServedByP1 / (simulationTime * serviceRate) * 100, 2)}%")
print(f"  Processor 2: {round(totalServedByP2 / (simulationTime * serviceRate) * 100, 2)}%")
print("Number of dropped requests:")
print(f"  Processor 1: {droppedByP1}")
print(f"  Processor 2: {droppedByP2}")
print(f"  Total: {totalDroppedRequests} ({round(totalDroppedRequests / totalArrivals * 100, 2)}%)")