#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minRepeats(string A, string B) {
		int answer = -1, n = A.size();

		auto helper = [&](int idx) {
			int j = 0, answer = 1;
			while (j < B.size() and B[j] == A[idx]) {
				j += 1;
				idx = (idx + 1) % n;
				if (idx == 0) answer += 1;
			}

			if (j == B.size()) return (idx == 0 ? answer - 1 : answer);
			return -1;
		};

		for (int i = 0; i < n; i++) {
			int count = helper (i);
			if (count != -1) {
				if (answer == -1) answer = count;
				else answer = min (answer, count);
			}
		}

		return answer;
	}
};