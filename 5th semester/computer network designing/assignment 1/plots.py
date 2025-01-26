import matplotlib.pyplot as plt

load = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
capacity1 = [7, 9, 11, 13, 15, 16, 18, 19, 21, 22]
capacity2 = [6, 8, 9, 11, 12, 14, 15, 16, 18, 19]
capacity3 = [5, 7, 9, 10, 11, 13, 14, 15, 16, 18]

plt.plot(capacity1, load, label='GOS 0.1')
plt.plot(capacity2, load, label='GOS 1')
plt.plot(capacity3, load, label='GOS 2')

plt.xlabel('Capacity')
plt.ylabel('Load')
plt.title('Service 2')

plt.legend()

plt.savefig('plot.png')