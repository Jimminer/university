e = 23
m = -1
t = -1
for i in range(50):
    m += 1
    print("M: " + str(m) + " Output: " + str(m % e))

    t += 1
    if t >= e:
        t = 0
    # print("Minus: " + str(t))