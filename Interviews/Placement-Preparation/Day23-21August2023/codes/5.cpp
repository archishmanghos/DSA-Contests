#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int longestEqualSubarray(vector<int>& nums, int k) {
		int answer = 0, maxFreq = 0, n = nums.size();
		set<pair<int, int>> s;
		vector<int> count(n + 2, 0);

		for (int i = 0, j = 0; j < n; j++) {
			count[nums[j]]++;
			if (s.find({1e9, nums[j]}) != s.end()) {
				auto it = s.find({1e9, nums[j]});
				s.erase(it);

			}

			s.insert({count[nums[j]], nums[j]});
			maxFreq = max(maxFreq, (*s.rbegin()).first);
			int deletions = (j - i + 1) - maxFreq;
			if (deletions > k) count[nums[i++]]--;
			else answer = max(answer, maxFreq);
		}

		return answer;
	}
};