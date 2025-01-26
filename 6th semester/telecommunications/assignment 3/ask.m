F = 1;
Fc = 150;
Fs = 200;
T = 0:0.01:5;
x = sin(2 * pi * F * T);
y = ammod(x, Fc, Fs);
TT = linspace(0, 10, length(y));

subplot(1, 2, 1)
plot(T, x)
title("Input signal")
subplot(1, 2, 2)
plot(TT, y, "r")
title("Modulated signal")
