#include<bits/stdc++.h>

int goodCount(int n, long long s, vector<int> &a) {
	long long sum = accumulate(a.begin(), a.end(), 0ll);
	int answer = 0;
	for (int i = 0; i < n; i++) {
		answer += (sum - a[i] == s);
	}

	return answer;
}