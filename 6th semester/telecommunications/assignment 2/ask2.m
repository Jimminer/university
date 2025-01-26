a = 10;
aVariation = 5;

b = 50;
bVariation = 20;

function [x,n] = stepseq(n0,n1,n2)
    % Generates x(n) = u(n-n0); n1 <= n <= n2
    % ------------------------------------------
    % [x,n] = stepseq(n0,n1,n2)
    n = [n1:n2]; x = [(n-n0) >= 0];
end

[a, a - aVariation, a + aVariation]
[x, n] = stepseq(a, a - aVariation, a + aVariation)
[b, b - bVariation, b + bVariation]
[x, n] = stepseq(b, b - bVariation, b + bVariation)
