#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minimumSeconds(vector<int>& nums) {
		unordered_map<int, vector<int>> ump;
		for (int i = 0; i < nums.size(); i++) {
			ump[nums[i]].push_back(i);
		}

		int answer = -1;
		for (auto i : ump) {
			int maxRounds = 0;
			for (int j = 1; j < i.second.size(); j++) {
				maxRounds = max(maxRounds, (i.second[j] - i.second[j - 1]) / 2);
			}

			maxRounds = max(maxRounds, ((int)nums.size() - i.second.back() + i.second[0]) / 2);

			if (answer == -1) answer = maxRounds;
			else answer = min(answer, maxRounds);
		}

		return answer;
	}
};