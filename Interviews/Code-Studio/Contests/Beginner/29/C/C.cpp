#include<bits/stdc++.h>

int minOperations(int n, vector<int> &a) {
	int count = 0, gcdd = -1;
	vector<int> cnt;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) count += 1;
		else {
			if (count) {
				cnt.push_back(count);
				if (gcdd == -1) gcdd = count;
				else gcdd = __gcd(gcdd, count);
			}
			count = 0;
		}
	}

	if (count) {
		cnt.push_back(count);
		if (gcdd == -1) gcdd = count;
		else gcdd = __gcd(gcdd, count);
	}

	int answer = 0;
	for (int i : cnt) answer += i / gcdd;
	return answer;
}