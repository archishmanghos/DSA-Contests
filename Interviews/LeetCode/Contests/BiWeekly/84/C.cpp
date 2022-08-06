long long taskSchedulerII(vector<int>& tasks, int space) {
	long long days = 0, n = tasks.size();
	map<long long, long long> lastTaskDone;
	for (int i = 0; i < n; i++) {
		if (lastTaskDone.find(tasks[i]) == lastTaskDone.end()) {
			days++;
		} else {
			days = max(days + 1, lastTaskDone[tasks[i]] + space + 1);
		}
		lastTaskDone[tasks[i]] = days;
	}

	return days;
}