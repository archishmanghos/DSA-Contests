#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxn = 300300;
const int INF = 1e9;
const int MOD = 1e9 + 7;
int N, C[mxn], M, U, V, visited[mxn];
vector<int> adj[mxn], newAdj[mxn];

void topoSort(int node, vector<int> &st) {
	if (visited[node]) return;
	visited[node] = 1;

	for (int child : adj[node]) topoSort(child, st);
	st.push_back(node);
}

void dfs(int node, vector<int> &MWSCC) {
	if (visited[node]) return;

	visited[node] = 1;
	if (C[node] < MWSCC[0]) MWSCC = {C[node], 1};
	else if (C[node] == MWSCC[0]) MWSCC[1] += 1;
	for (int child : newAdj[node]) dfs(child, MWSCC);
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> C[i];
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> U >> V;
		adj[U].push_back(V);
		newAdj[V].push_back(U);
	}

	vector<int> st;
	memset(visited, 0, (N + 2) * sizeof(int));
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) topoSort(i, st);
	}

	memset(visited, 0, (N + 2) * sizeof(int));
	int minCost = 0, ways = 1;
	while (st.size()) {
		int curNode = st.back();
		st.pop_back();
		if (visited[curNode]) continue;

		vector<int> minWeightinSCC(2);
		minWeightinSCC[0] = INF;
		minWeightinSCC[1] = 0;

		dfs(curNode, minWeightinSCC);
		minCost += minWeightinSCC[0];
		ways = (ways * minWeightinSCC[1]) % MOD;
	}

	cout << minCost << ' ' << ways;
	return 0;
}