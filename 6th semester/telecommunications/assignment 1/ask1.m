t = 2
A = [1 3; 5 6]
u = [2 4 5]
u1 = [4 5 0 2]
u2 = u1 + 3

upol = u1 * t
upol2 = u1 .* u2

length(u1)
size(u1)

A(1, 2)
A(1, 1:2)

% help plot

t = 0:0.1:1;
plot(t);
title("t (0 -> 1, 0.1 step)");

