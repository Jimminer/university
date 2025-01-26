
import matplotlib.pyplot as plt

def draw_graph(x1_values, x2_values, y1_values, y2_values, title, xlabel, ylabel, filename):
    plt.figure()
    plt.plot(x1_values, y1_values, label='Service 1')
    plt.plot(x2_values, y2_values, label='Service 2')
    
    plt.title(title)
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.legend()
    
    plt.savefig(filename)
    plt.show()

x1_values = [500, 750, 1000, 1250, 1500, 1750, 2000]
x2_values = [1000, 1250, 1500, 1750, 2000, 2250, 2500]


y11_values = [0.00, 0.00, 0.00, 0.01, 0.02, 0.06, 0.11]
y21_values = [0.00, 0.00, 0.00, 0.01, 0.02, 0.06, 0.11]

y12_values = [5.00, 5.00, 5.00, 5.01, 5.02, 5.05, 5.09]
y22_values = [0.00, 0.00, 0.00, 0.01, 0.02, 0.05, 0.10]

xlabel = "Packet arrival rate"
ylabel = "Packet loss probability percentage (%)"

# Customize your graph for Plot 1
title1 = 'Without priority'
filename1 = 'plot1.png'

# Call the function to draw the first graph and save it as a PNG file
draw_graph(x1_values, x2_values, y11_values, y21_values, title1, xlabel, ylabel, filename1)


# Customize your graph for Plot 2
title2 = 'With priority'
filename2 = 'plot2.png'

# Call the function to draw the second graph and save it as a PNG file
draw_graph(x1_values, x2_values, y12_values, y22_values, title2, xlabel, ylabel, filename2)