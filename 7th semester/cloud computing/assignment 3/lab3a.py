# Cloud Computing: Load balancing Lab 3
# Distribute requests among 2 processors with a shared queue
# Requests arrive at a rate of 5 per second in an exponential distribution and are served at a rate of 6 per second (each processor can process independently). The queue can hold up to 10 requests. Simulate for 1000 seconds.
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

queue = []
p1BusyUntilTime = float('inf')
p2BusyUntilTime = float('inf')
totalArrivals = 0
totalDepartures = 0
droppedRequests = 0
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

        if len(queue) < queueSize:
            queue.append(currentTime)
        
        else:
            droppedRequests += 1

        nextArrival = currentTime + random.expovariate(arrivalRate)

    if queue:
        if p1BusyUntilTime == float('inf'):
            p1BusyUntilTime = currentTime + random.expovariate(serviceRate)
            totalWaitTime += currentTime - queue.pop(0)

        elif p2BusyUntilTime == float('inf'):
            p2BusyUntilTime = currentTime + random.expovariate(serviceRate)
            totalWaitTime += currentTime - queue.pop(0)

print(f"Average waiting time in the queue: {round(totalWaitTime / totalDepartures, 2)}")
print(f"Total number of arrivals: {totalArrivals}")
print(f"Total number of departures: {totalDepartures}")
print("Total number of requests served by each processor:")
print(f"  Processor 1: {totalServedByP1}")
print(f"  Processor 2: {totalServedByP2}")
print("Average utilization of each processor:")
print(f"  Processor 1: {round(totalServedByP1 / (simulationTime * serviceRate) * 100, 2)}%")
print(f"  Processor 2: {round(totalServedByP2 / (simulationTime * serviceRate) * 100, 2)}%")
print(f"Number of dropped requests: {droppedRequests} ({round(droppedRequests / totalArrivals * 100, 2)}%)")