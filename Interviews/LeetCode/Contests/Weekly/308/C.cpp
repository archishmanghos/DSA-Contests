int garbageCollection(vector<string>& garbage, vector<int>& travel) {
	char trucks[3] = {'P', 'G', 'M'};
	int ans = 0;
	for (int i = 0; i < 3; i++) {
		int time = 0;
		for (int j = garbage.size() - 1; j >= 0; j--) {
			for (char c : garbage[j]) {
				time += c == trucks[i];
			}
			if (time) {
				if (j > 0) time += travel[j - 1];
			}
		}
		ans += time;
	}

	return ans;
}