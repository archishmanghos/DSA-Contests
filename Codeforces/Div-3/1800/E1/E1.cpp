#include <bits/stdc++.h>
#define int long long
using namespace std;

int N, K;
string S1, S2;

class DSU {
	vector<int> size, parent;
	int n;

public:
	map<int, multiset<char>> mp;
	DSU (int n, string &s) {
		this->n = n;
		size.assign(n, 1);
		parent.assign(n, 0);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			mp[i].insert(s[i]);
		}
	}

	int findParent(int node) {
		if (node == parent[node]) return node;
		return parent[node] = findParent(parent[node]);
	}

	void unionNode (int u, int v) {
		int pu = findParent(u), pv = findParent(v);
		if (pu == pv) return;

		if (size[pu] >= size[pv]) {
			size[pu] += size[pv];
			for (char c : mp[pv]) mp[pu].insert(c);
			parent[pv] = pu;
		} else {
			size[pv] += size[pu];
			for (char c : mp[pu]) mp[pv].insert(c);
			parent[pu] = pv;
		}
	}
};

void solve() {
	cin >> N >> K >> S1 >> S2;
	DSU dsu1(N, S1), dsu2(N, S2);

	for (int i = 0; i < N; i++) {
		if (i + K < N) dsu1.unionNode(i, i + K);
		if (i + K + 1 < N) dsu1.unionNode(i, i + K + 1);
		if (i + K < N) dsu2.unionNode(i, i + K);
		if (i + K + 1 < N) dsu2.unionNode(i, i + K + 1);
	}

	for (int i = 0; i < N; i++) {
		if (dsu1.findParent(i) == i) {
			if (dsu1.mp[i] != dsu2.mp[i]) {
				cout << "NO" << '\n';
				return;
			}
		}
	}

	cout << "YES" << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}