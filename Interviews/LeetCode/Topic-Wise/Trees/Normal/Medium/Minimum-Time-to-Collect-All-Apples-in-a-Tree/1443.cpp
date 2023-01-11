#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> adj[100100];
	bool vis[100100], mark[100100];
	bool markSubtree (int node, vector<bool> &apple) {
		bool check = apple[node];

		for (int child : adj[node]) {
			if (!vis[child]) {
				vis[child] = true;
				check |= markSubtree (child, apple);
			}
		}

		return mark[node] = check;
	}

	int dfs (int node) {
		if (!mark[node]) return 0;
		if (vis[node]) return 0;

		vis[node] = true;
		int answer = node == 0 ? 0 : 2;
		for (int child : adj[node]) {
			answer += dfs (child);
		}

		return answer;
	}

	int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
		for (auto e : edges) {
			adj[e[0]].push_back(e[1]);
			adj[e[1]].push_back(e[0]);
		}

		memset (vis, false, sizeof (vis));
		memset (mark, false, sizeof (mark));
		vis[0] = true;
		bool check = markSubtree (0, hasApple);

		memset (vis, false, sizeof (vis));
		return dfs (0);
	}
};