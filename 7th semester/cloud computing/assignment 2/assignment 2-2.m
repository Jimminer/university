simulation_time = 1000;

% Define test cases as [lambda, mu]
cases = [2, 6; 4, 6; 5.9, 6; 8, 6; 15, 6];

for case_idx = 1:size(cases, 1)
    lambda = cases(case_idx, 1);
    mu = cases(case_idx, 2);

    % Generate arrivals and service times
    interarrival_times = exprnd(1/lambda, 1, N);
    arrival_times = cumsum(interarrival_times);
    arrival_times = arrival_times(arrival_times <= simulation_time);

    service_times = exprnd(1/mu, 1, length(arrival_times));

    departure_times = zeros(1, length(arrival_times));
    for i = 1:length(arrival_times)
        if i == 1
            departure_times(i) = arrival_times(i) + service_times(i);
        else
            departure_times(i) = max(arrival_times(i), departure_times(i-1)) + service_times(i);
        end
    end

    % Metrics
    waiting_times = departure_times - arrival_times - service_times;
    avg_waiting_time = mean(waiting_times);
    total_service_time = sum(service_times);
    processor_utilization = total_service_time / simulation_time;
    tasks_in_system = cumsum(event_type);

    fprintf('\nCase %d: λ = %.1f, μ = %.1f\n', case_idx, lambda, mu);
    fprintf('  Average Waiting Time: %.2f\n', avg_waiting_time);
    fprintf('  Total Arrivals: %d\n', length(arrival_times));
    fprintf('  Total Departures: %d\n', length(departure_times));
    fprintf('  Processor Utilization: %.2f\n', processor_utilization);
end
