#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void dfs (int node, int parent, int &answer, vector<vector<int>> &undirectedadj, vector<set<int>> &directedadj) {
		for (int child : undirectedadj[node]) {
			if (child != parent) {
				if (directedadj[child].find(node) == directedadj[child].end()) answer++;
				dfs (child, node, answer, undirectedadj, directedadj);
			}
		}
	}
	int minReorder(int n, vector<vector<int>>& connections) {
		vector<vector<int>> undirectedadj (n);
		vector<set<int>> directedadj (n);
		for (auto i : connections) {
			undirectedadj[i[0]].push_back(i[1]);
			undirectedadj[i[1]].push_back(i[0]);
			directedadj[i[0]].insert(i[1]);
		}

		int answer = 0;
		dfs(0, -1, answer, undirectedadj, directedadj);
		return answer;
	}
};