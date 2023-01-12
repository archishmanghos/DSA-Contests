#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> adj[100100];
	vector<int> getAns (int node, int parent, vector<int> &ans, string &labels) {
		vector<int> count (26, 0);
		count[labels[node] - 'a'] = 1;

		for (int child : adj[node]) {
			if (child != parent) {
				vector<int> temp = getAns (child, node, ans, labels);
				for (int i = 0; i < 26; i++) count[i] += temp[i];
			}
		}

		ans[node] = count[labels[node] - 'a'];
		return count;
	}
	vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
		for (auto edge : edges) {
			adj[edge[0]].push_back(edge[1]);
			adj[edge[1]].push_back(edge[0]);
		}

		vector<int> answer (n, 0), count (26, 0);
		vector<int> temp = getAns (0, -1, answer, labels);

		return answer;
	}
};