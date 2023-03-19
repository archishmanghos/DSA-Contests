#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long findScore(vector<int>& nums) {
		long long answer = 0;
		priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
		int visited[nums.size()];
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < nums.size(); i++) {
			pq.push({nums[i], i});
		}

		while (!pq.empty()) {
			auto it = pq.top();
			pq.pop();
			int element = it[0], idx = it[1];
			if (visited[idx]) continue;
			answer += element;
			visited[idx] = 1;
			if (idx - 1 >= 0) visited[idx - 1] = 1;
			if (idx + 1 < nums.size()) visited[idx + 1] = 1;
		}

		return answer;
	}
};