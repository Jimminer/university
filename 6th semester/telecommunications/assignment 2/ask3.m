n = 0:0.1:10;
sigma = 0.3;
omega = 0.01;

function x = exponential(n, sigma, omega)
    x = exp((sigma + 1i * omega) * n);
end

x = exponential(n, sigma, omega);
x
plot(real(n),x)
