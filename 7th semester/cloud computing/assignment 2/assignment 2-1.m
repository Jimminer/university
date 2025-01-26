%%%%%%%%% 1.1

lambda = 15; % Arrival rate
simulation_time = 1000; % Total simulation time
N = 1000; % Number of potential arrivals

% Generate inter-arrival times (exponential)
interarrival_times = exprnd(1/lambda, 1, N);

% Compute cumulative arrival times
arrival_times = cumsum(interarrival_times);

% Retain only arrivals within the simulation time
arrival_times = arrival_times(arrival_times <= simulation_time);

% Plot arrivals over time
subplot(2, 2, 1);
stairs(arrival_times, 1:length(arrival_times), 'o-');
title('Task Arrivals Over Time');
xlabel('Time');
ylabel('Cumulative Number of Arrivals');




%%%%%%%%% 1.2

mu = 6; % Service rate

% Generate service times (exponential)
service_times = exprnd(1/mu, 1, length(arrival_times));

% Compute departure times
departure_times = zeros(1, length(arrival_times));
for i = 1:length(arrival_times)
    if i == 1
        departure_times(i) = arrival_times(i) + service_times(i);
    else
        departure_times(i) = max(arrival_times(i), departure_times(i-1)) + service_times(i);
    end
end

% Plot arrivals and departures over time
subplot(2, 2, 2);
hold on;
stairs(arrival_times, 1:length(arrival_times), 'o-', 'DisplayName', 'Arrivals');
stairs(departure_times, 1:length(departure_times), 'x-', 'DisplayName', 'Departures');
title('Arrivals and Departures Over Time');
xlabel('Time');
ylabel('Cumulative Events');
legend;
hold off;



%%%%%%%%% 1.3

% Calculate number of tasks in the system
events = sort([arrival_times, departure_times]);
event_type = [ones(1, length(arrival_times)), -ones(1, length(departure_times))]; % 1 for arrival, -1 for departure
[event_timeline, idx] = sort(events);
event_type = event_type(idx);

tasks_in_system = cumsum(event_type);

% Plot tasks in the system over time
subplot(2, 2, [3, 4]);
stairs(event_timeline, tasks_in_system, 'k-', 'LineWidth', 1.5);
title('Tasks in the System Over Time');
xlabel('Time');
ylabel('Number of Tasks in System');



%%%%%%%%% 1.4

% a. Average waiting time
waiting_times = departure_times - arrival_times - service_times;
avg_waiting_time = mean(waiting_times);

% b. Total arrivals
total_arrivals = length(arrival_times);

% c. Total departures
total_departures = length(departure_times);

% d. Processor utilization
total_service_time = sum(service_times);
processor_utilization = total_service_time / simulation_time;

fprintf('Simulation Time %d, λ = %.1f, μ = %.1f\n', simulation_time, lambda, mu);
fprintf('  Average Waiting Time: %.2f\n', avg_waiting_time);
fprintf('  Total Arrivals: %d\n', total_arrivals);
fprintf('  Total Departures: %d\n', total_departures);
fprintf('  Processor Utilization: %.2f\n', processor_utilization);
