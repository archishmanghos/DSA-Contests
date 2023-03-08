#include<bits/stdc++.h>

int getLongestWeirdSequence(int n, vector<int> a) {
	unordered_map<int, int> mp;
	int answer = 0;
	for (int i = 0; i < n; i++) mp[a[i]] += 1;
	for (int i = 0; i < n; i++) {
		if (mp.find(a[i] + 1) == mp.end()) mp[a[i] + 1] = 0;
		if (mp.find(a[i] - 1) == mp.end()) mp[a[i] - 1] = 0;
		answer = max(answer, max(mp[a[i]] + mp[a[i] - 1], mp[a[i]] + mp[a[i] + 1]));
	}

	return answer;
}
