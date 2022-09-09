#include <bits/stdc++.h>

int ProgrammingTime(int n, int a, vector<int> &p ) {
	map<int, int> lastTime;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (lastTime.find(p[i]) != lastTime.end()) {
			if (ans <= lastTime[p[i]] + a) {
				ans += (lastTime[p[i]] + a - ans + 1);
			}
		}
		lastTime[p[i]] = ans;
		ans += 1;
	}

	return ans;
}