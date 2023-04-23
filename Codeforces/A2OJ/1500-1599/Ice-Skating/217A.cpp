#include <bits/stdc++.h>
using namespace std;

class DSU {
	vector<int> size, parent;
	int n;

	int findParent(int node) {
		if (node == parent[node]) return node;
		return parent[node] = findParent(parent[node]);
	}

public:
	DSU (int n) {
		this->n = n;
		size.assign(n, 1);
		parent.assign(n, 0);
		for (int i = 0; i < n; i++) parent[i] = i;
	}

	bool unionNode (int u, int v) {
		int pu = findParent(u), pv = findParent(v);
		if (pu == pv) return true;

		if (size[pu] >= size[pv]) {
			size[pu] += size[pv];
			parent[pv] = pu;
		} else {
			size[pv] += size[pu];
			parent[pu] = pv;
		}

		return false;
	}

	int getComponents() {
		set<int> s;
		for (int i = 0; i < n; i++) s.insert(findParent(i));
		return (int)s.size();
	}
};

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N; cin >> N;
	DSU dsu(N);

	vector<pair<int, int>> A(N);
	for (int i = 0; i < N; i++) cin >> A[i].first >> A[i].second;

	for (int i = 0; i + 1 < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (A[i].first == A[j].first or A[i].second == A[j].second) dsu.unionNode(i, j);
		}
	}

	cout << dsu.getComponents() - 1;
	return 0;
}