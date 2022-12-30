#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
		unordered_map<int, set<int>> ump;
		for (auto log : logs) {
			ump[log[0]].insert(log[1]);
		}

		vector<int> ans (k, 0);
		for (auto key : ump) {
			ans[key.second.size() - 1] += 1;
		}

		return ans;
	}
};