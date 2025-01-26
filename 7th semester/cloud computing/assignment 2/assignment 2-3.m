queue_capacity = 10; % Maximum queue size
queue_length = 0; % Initialize queue length
dropped_tasks = 0; % Count of dropped tasks

departure_times = [];
for i = 1:length(arrival_times)
    if queue_length < queue_capacity
        % Accept the task
        if i == 1
            departure_times(i) = arrival_times(i) + service_times(i);
        else
            departure_times(i) = max(arrival_times(i), departure_times(i-1)) + service_times(i);
        end
        queue_length = queue_length + 1;
    else
        % Drop the task
        dropped_tasks = dropped_tasks + 1;
    end
    queue_length = max(0, queue_length - 1); % Update queue after departure
end

% Metrics
fprintf('Dropped Tasks: %d\n', dropped_tasks);
