#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxWeightCell(int N, vector<int> Edge) {
		vector<int> freq (N, 0), answer (2, 0);
		for (int i = 0; i < N; i++) {
			if (Edge[i] == -1) continue;
			freq[Edge[i]] += i;
			if (freq[Edge[i]] >= answer[0]) {
				if (freq[Edge[i]] == answer[0]) {
					if (Edge[i] > answer[1]) answer[1] = Edge[i];
				} else {
					answer = {freq[Edge[i]], Edge[i]};
				}
			}
		}

		return answer[1];
	}
};