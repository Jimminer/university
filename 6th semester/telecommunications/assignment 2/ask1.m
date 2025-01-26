a = 10;
aVariation = 5;

b = 50;
bVariation = 20;

function [x,n] = impseq(n0,n1,n2)
    % Generates x(n) = delta(n-n0); n1 <= n,n0 <= n2
    % [x,n] = impseq(n0,n1,n2)

    if ((n0 < n1) || (n0 > n2) || (n1 > n2))
        error('arguments must satisfy n1 <= n0 <= n2')
    end

    n = [n1:n2];

    %x = [zeros(1,(n0-n1)), 1, zeros(1,(n2-n0))];

    x = [(n-n0) == 0];

end

[a, a - aVariation, a + aVariation]
[x, n] = impseq(a, a - aVariation, a + aVariation)
[b, b - bVariation, b + bVariation]
[x, n] = impseq(b, b - bVariation, b + bVariation)
