Fm = 25;
Fc = 400;
mf = 10;
T = 0:0.0001:0.1;
m = sin(2 * pi * Fm * T);
subplot(3, 1, 1);
plot(T, m);
xlabel("Time (s)");
ylabel("Amplitude (V)");
title("Message Signal");
grid on;

c = sin(2 * pi * Fc * T);
subplot(3, 1, 2);
plot(T, c);
xlabel("Time (s)");
ylabel("Amplitude (V)");
title("Carrier Signal");
grid on;

y = sin(2 * pi * Fc * T + (mf .* sin(2 * pi * Fm * T)));
subplot(3, 1, 3);
plot(T, y);
xlabel("Time (s)");
ylabel("Amplitude (V)");
title("Frequency Modulated Signal");
grid on;
