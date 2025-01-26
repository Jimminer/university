n = 0:0.1:10;
A = 5
omega = 1;
theta = pi/2;

function x = cosine(n, A, omega, theta)
    x = A * cos(omega * n + theta);
end

x = cosine(n, A, omega, theta);
x
plot(n, x)
