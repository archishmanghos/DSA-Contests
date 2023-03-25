#include <bits/stdc++.h>
using namespace std;

class DSU {
	int n;
	vector<int> parent, size;
	int findPar (int node) {
		if (parent[node] == node) return node;
		return parent[node] = findPar (parent[node]);
	}
public:
	DSU(int n) {
		this->n = n;
		parent.assign(n, 1);
		size.assign(n, 1);
		for (int i = 0; i < n; i++) parent[i] = i;
	}

	void unionNode (int u, int v) {
		int parU = findPar(u), parV = findPar(v);
		if (parU == parV) return;

		if (size[parU] >= size[parV]) {
			parent[parV] = parU;
			size[parU] += size[parV];
		} else {
			parent[parU] = parV;
			size[parV] += size[parU];
		}
	}

	vector<int> getComponents () {
		set<int> s;
		vector<int> answer;
		for (int i = 0; i < n; i++) {
			int par = findPar(i);
			if (s.find(par) == s.end()) {
				answer.push_back(size[par]);
				s.insert(par);
			}
		}

		return answer;
	}
};

class Solution {
public:
	long long countPairs(int n, vector<vector<int>>& edges) {
		DSU dsu(n);
		for (auto edge : edges) {
			dsu.unionNode(edge[0], edge[1]);
		}

		vector<int> sizes = dsu.getComponents();
		long long answer = 0, sum = accumulate(sizes.begin(), sizes.end(), 0ll);
		for (int i = 0; i < sizes.size(); i++) {
			sum -= sizes[i];
			answer += 1ll * sizes[i] * sum;
		}

		return answer;
	}
};