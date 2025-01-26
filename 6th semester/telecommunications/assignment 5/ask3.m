fs = 2000;
fc = 200;
N = 500;
t = (1:N)/fs;
x = sin(2*pi*30*t) + 2*sin(2*pi*60*t);
fDev = 50;

y = fmmod(x, fc, fs, fDev);

noise = randn(1, N);

# 5 dB
db = 5;
scale = 10^(db/10) * (1/var(noise)) * 3.16;
z = y + (noise * scale);

% Noisy signal plot
figure;
subplot(3,1,1);
plot(t, z);
title('Noisy FM Signal (5 dB)');
xlabel('Time (s)');
ylabel('Amplitude');

% Spectrum analyzed signal plot
subplot(3,1,2);
pwelch(z, [], [], [], fs);
title('Spectrum Analysis');

% Demodulated signal plot
y_demod = fmdemod(z, fc, fs);
t_demod = (1:length(y_demod)) / fs;
subplot(3,1,3)
plot(t_demod, y_demod);
title('Demodulated FM Signal');
xlabel('Time (s)');
ylabel('Amplitude');
