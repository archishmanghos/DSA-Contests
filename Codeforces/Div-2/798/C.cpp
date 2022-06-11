#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 3e5 + 5;
const int INF = 1e18 + 7;

int T, N, U, V;
vector<int> adj[mxN];

int dfs(int node, vector<int> &savesOfNode, vector<bool> &visited){
	if(visited[node]) return 1;
	visited[node] = true;
	int ans = 0;
	for(int child : adj[node]){
		ans += dfs(child, savesOfNode, visited);
	}

	return savesOfNode[node] = ans;
}

int infection(int node, vector<int> &savesOfNode, vector<bool> &visited){
	int saves = 0;
	int child1 = adj[node].size() > 0 ? adj[node][0] : -1;
	int child2 = adj[node].size() > 1 ? adj[node][1] : -1;
	int child3 = adj[node].size() > 2 ? adj[node][2] : -1;

	if(visited[child1]) child1 = -1;
	if(visited[child2]) child2 = -1;
	if(visited[child3]) child3 = -1;

	int leftChild = -1, rightChild = -1;
	if(child1 != -1) leftChild = child1;
	if(child2 != -1){
		if(leftChild != -1) rightChild = child2;
		else leftChild = child2;
	}
	if(child3 != -1){
		if(leftChild != -1) rightChild = child3;
		else leftChild = child3;
	}

	if(leftChild != -1 and visited[leftChild]) leftChild = -1;
	if(leftChild != -1) visited[leftChild] = true;
	if(rightChild != -1 and visited[rightChild]) rightChild = -1;
	if(rightChild != -1) visited[rightChild] = true;

	if(leftChild == -1 and rightChild == -1) return 0;
	else if(leftChild == -1) saves = savesOfNode[rightChild];
	else if(rightChild == -1) saves = savesOfNode[leftChild];
	else saves = max(infection(leftChild, savesOfNode, visited) + savesOfNode[rightChild], infection(rightChild, savesOfNode, visited) + savesOfNode[leftChild]);

	return saves;
}

void solve() {
	cin >> N;
	for(int i = 1; i <= N; i++) adj[i].clear();
	for(int i = 1; i <= N - 1; i++){
		cin >> U >> V;
		adj[U].push_back(V);
		adj[V].push_back(U);
	}

	vector<int> savesOfNode(N + 2, 0);
	vector<bool> visited(N + 2, false);
	dfs(1, savesOfNode, visited);
	visited.assign(N + 2, false);
	for(int i = 2; i <= N; i++) savesOfNode[i] -= 1;
	visited[1] = true;
	cout << infection(1, savesOfNode, visited) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> T;
    while (T--)
        solve();

    return 0;
}