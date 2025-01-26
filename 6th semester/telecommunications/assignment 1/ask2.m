t = -20:0.1:20;

function [y] = u(t, step)
    for i = 1:length(t)
        if ((t(i) - step) > 0)
            y(i) = 1;
        elseif ((t(i) - step) < 0)
            y(i) = 0;
        end
    end
end

function [y] = r(t, step)
    for i = 1:length(t)
        if ((t(i) - step) >= 0)
            y(i) = t(i);
        else
            y(i) = 0;
        end
    end
end

y1 = 3 .* u(t, 0);
y2 = 2 .* r(t, 3);
y3 = 3 .* u(t, 0) - 2 .* r(t, 3);
y4 = 6 .* u(t, 0) * 2 .* r(t, 3);

subplot(2, 2, 1);
plot(t, y1);
title("y1(t) = 3u(t) ");
xlabel("t");
ylabel("y1(t)");

subplot(2, 2, 2);
plot(t, y2);
title("y2(t) = 2r(t + 3)");
xlabel("t");
ylabel("y2(t)");

subplot(2, 2, 3);
plot(t, y3);
title("y3(t) = 3u(t) - 2r(t + 3)");
xlabel("t");
ylabel("y3(t)");

subplot(2, 2, 4);
plot(t, y4);
title("y4(t) = 6u(t) * 2r(t+3)");
xlabel("t");
ylabel("y4(t)");

