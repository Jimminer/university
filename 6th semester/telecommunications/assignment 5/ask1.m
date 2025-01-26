fs = 2000;
fc = 200;
N = 500;
t = (1:N)/fs;
x = sin(2*pi*30*t) + 2*sin(2*pi*60*t);
fDev = 50;

y = fmmod(x, fc, fs, fDev);

noise = randn(1,N);
scale = (1/var(noise)) * 3.16;
z = y + (noise*scale);

# Original signal plot
figure;
subplot(3,1,1);
plot(t, x);
title('Original Signal');
xlabel('Time (s)');
ylabel('Amplitude');

# Frequency modulated signal plot
subplot(3,1,2);
plot(t, y);
title('Frequency Modulated Signal');
xlabel('Time (s)');
ylabel('Amplitude');

# Noisy signal plot
subplot(3,1,3);
plot(t, z);
title('Noisy FM Signal');
xlabel('Time (s)');
ylabel('Amplitude');
