#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string caseSort(string str, int n) {
		vector<int> cnt (58, 0);
		for (char c : str) cnt[c - 'A'] += 1;
		int upper = 0, lower = 32;
		string answer = str;
		for (int i = 0; i < n; i++) {
			if (answer[i] >= 'A' and answer[i] <= 'Z') {
				while (!cnt[upper]) upper += 1;
				answer[i] = (upper + 'A');
				cnt[upper] -= 1;
			} else {
				while (!cnt[lower]) lower += 1;
				answer[i] = (lower + 'A');
				cnt[lower] -= 1;
			}
		}

		return answer;
	}
};