Fs = 1000;
Fc = 150;
T = (0:1/Fs:0.2)';
x = sin(2 * pi * 90 * T) + 2 * sin(2 * pi * 120 * T);
fDev = 50;
y = fmmod(x, Fc, Fs, fDev);

plot(T, x, "c", T, y, "b--")
xlabel("Time (s)")
ylabel("Amplitude")
legend("Original Signal", "Modulated Signal")
