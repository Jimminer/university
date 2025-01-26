x1 = [1, 2, 3, 4, 5, 6, 7, 8, 9];
n1 = [0, 1, 2, 3, 4, 5, 6, 7, 8];
x2 = [10, 20, 30];
n2 = [0, 1, 2];

function [y,n] = sigadd(x1,n1,x2,n2)
    % implements y(n) = x1(n)+x2(n)
    % -----------------------------
    % [y,n] = sigadd(x1,n1,x2,n2)
    % y = sum sequence over n, which includes n1 and n2
    % x1 = first sequence over n1
    % x2 = second sequence over n2 (n2 can be different from n1)
    n = min(min(n1),min(n2)):max(max(n1),max(n2)); % duration of y(n)
    y1 = zeros(1,length(n)); y2 = y1; % initialization
    y1(find((n>=min(n1))&(n<=max(n1))==1))=x1; % x1 with duration of y
    y2(find((n>=min(n2))&(n<=max(n2))==1))=x2; % x2 with duration of y
    y = y1+y2; % sequence addition
end

[y, n] = sigadd(x1, n1, x2, n2);

subplot(3,1,1);
stem(n1, x1);
xlabel('n');
ylabel('x_1[n]');
title('x_1[n]');

subplot(3,1,2);
stem(n2, x2);
xlabel('n');
ylabel('x_2[n]');
title('x_2[n]');

subplot(3,1,3);
stem(n, y);
xlabel('n');
ylabel('y[n]');
title('x_1[n] + x_2[n]');
