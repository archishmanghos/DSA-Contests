#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string findOrder(string dict[], int N, int K) {
		vector<int> adj[26], indegree(K, 0);
		for (int i = 0; i < N - 1; i++) {
			int j = i + 1;
			int N1 = min (dict[i].size(), dict[j].size());
			for (int k = 0; k < N1; k++) {
				if (dict[i][k] != dict[j][k]) {
					adj[dict[i][k] - 'a'].push_back(dict[j][k] - 'a');
					indegree[dict[j][k] - 'a'] += 1;
					break;
				}
			}
		}

		queue<int> q;
		for (int i = 0; i < K; i++) {
			if (!indegree[i]) {
				q.push(i);
				indegree[i] -= 1;
			}
		}

		string answer = "";
		while (!q.empty()) {
			int node = q.front();
			q.pop();

			answer += (node + 'a');
			for (int child : adj[node]) indegree[child] -= 1;
			for (int i = 0; i < K; i++) {
				if (!indegree[i]) {
					q.push(i);
					indegree[i] -= 1;
				}
			}
		}

		return answer;
	}
};