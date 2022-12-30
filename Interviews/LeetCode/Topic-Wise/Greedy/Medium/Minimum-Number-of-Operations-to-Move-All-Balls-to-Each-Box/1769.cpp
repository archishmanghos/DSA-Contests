#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> minOperations(string boxes) {
		vector<int> answer (boxes.size());
		for (int i = 0; i < boxes.size(); i++) {
			int dist = 0;
			for (int j = i - 1; j >= 0; j--) if (boxes[j] == '1') dist += i - j;
			for (int j = i + 1; j < boxes.size(); j++) if (boxes[j] == '1') dist += j - i;
			answer[i] = dist;
		}

		return answer;
	}
};