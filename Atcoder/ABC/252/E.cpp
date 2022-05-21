#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <D:/archishmanghos/Practice/Online_Judges/archiDebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int N, M, A, B, C;
vector<vector<pair<int, pair<int, int>>>> adj(mxN);

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N >> M;
	for(int i = 1; i <= M; i++){
		cin >> A >> B >> C;
		adj[A].push_back({B, {C, i}});
		adj[B].push_back({A, {C, i}});
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, 1});
	vector<int> ans(N + 2, 0), dist(N + 2, INF);
	dist[1] = 0;

	while(!pq.empty()){
		int curNode = pq.top().second, curNodeWeight = pq.top().first;
		pq.pop();

		for(auto child : adj[curNode]){
			int curChild = child.first, curChildWeight = child.second.first, curIndex = child.second.second;
			if(dist[curChild] > dist[curNode] + curChildWeight){
				dist[curChild] = dist[curNode] + curChildWeight;
				ans[curChild] = curIndex;
				pq.push({dist[curChild], curChild});
			}
		}
	}

	for(int i = 2; i <= N; i++) cout << ans[i] << ' ';

    return 0;
}