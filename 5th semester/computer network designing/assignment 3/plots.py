
import matplotlib.pyplot as plt

def graphTwoPlots(x1_values, x2_values, y1_values, y2_values, title, xlabel, ylabel, filename):
    plt.figure()
    plt.plot(x1_values, y1_values, label='Service 1')
    plt.plot(x2_values, y2_values, label='Service 2')
    
    plt.title(title)
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.legend()
    
    plt.savefig(filename)

def graphOnePlot(x_values, y_values, title, xlabel, ylabel, filename):
    plt.figure()
    plt.plot(x_values, y_values)
    
    plt.title(title)
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    
    plt.savefig(filename)

def graph1():
    x1Values = [0.2, 0.24, 0.28, 0.32, 0.36, 0.4]
    x2Values = [0.3, 0.36, 0.42, 0.48, 0.54, 0.6]

    xValues = ["0.2, 0.3", "0.24, 0.36", "0.28, 0.42", "0.32, 0.48", "0.36, 0.54", "0.4, 0.6"]
    yValues = [51.158, 62.984, 71.363, 77.434, 81.941, 85.356]

    xLabel = "Packet arrival rate (service 1, service 2)"
    yLabel = "Packet loss probability percentage (%)"
    
    title = "Packet loss probability"

    filename = "plot1.png"

    graphOnePlot(xValues, yValues, title, xLabel, yLabel, filename)

def graph2():
    x1Values = [0.2, 0.24, 0.28, 0.32, 0.36, 0.4]
    x2Values = [0.3, 0.36, 0.42, 0.48, 0.54, 0.6]

    xValues = ["0.2, 0.3", "0.24, 0.36", "0.28, 0.42", "0.32, 0.48", "0.36, 0.54", "0.4, 0.6"]
    yValues = [27, 28, 29, 29, 29, 30]

    xLabel = "Packet arrival rate (service 1, service 2)"
    yLabel = "Minimum wavelength for 2% packet loss"

    title = "Minimum wavelength for 2% packet loss"

    filename = "plot2.png"

    graphOnePlot(xValues, yValues, title, xLabel, yLabel, filename)

def graph3():
    xValues = [40, 45, 50, 55, 60]
    yValues = [44.837, 62.005, 71.362, 77.096, 80.941]

    xLabel = "User groups"
    yLabel = "Packet loss probability percentage (%)"

    title = "Packet loss probability (0.28, 0.42 arrival rates)"

    filename = "plot3.png"

    graphOnePlot(xValues, yValues, title, xLabel, yLabel, filename)

graph1()
graph2()
graph3()