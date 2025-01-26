fs = 2000;
fc = 200;
N = 500;
t = (1:N)/fs;
x = sin(2*pi*30*t) + 2*sin(2*pi*60*t);
fDev = 50;

y = fmmod(x, fc, fs, fDev);

noise = randn(1,N);

# 2 dB
db = 2;
scale = 10^(db/10) * (1/var(noise)) * 3.16;
z = y + (noise * scale);

# 2 dB noise plot
figure;
subplot(2,1,1);
plot(t, z);
title('Noisy FM Signal (2 dB)');
xlabel('Time (s)');
ylabel('Amplitude');

# 10 dB
db = 10;
scale = 10^(db/10) * (1/var(noise)) * 3.16;
z = y + (noise * scale);

# 10 dB noise plot
subplot(2,1,2);
plot(t, z);
title('Noisy FM Signal (10 dB)');
xlabel('Time (s)');
ylabel('Amplitude');
