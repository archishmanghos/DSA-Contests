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

int T, N, P[mxN];

void solve() {
    cin >> N;

    set<int> nodes;
    for(int i = 1; i <= N; i++){
    	cin >> P[i];
    	nodes.insert(P[i]);
    }

    if(N == 1){
    	cout << 1 << '\n' << 1 << '\n' << 1 << '\n';
    	cout << '\n';
    	return;
    }

    set<int> leafNodes;
    for(int i = 1; i <= N; i++){
    	if(nodes.find(i) == nodes.end()){
    		leafNodes.insert(i);
    	}
    }

    cout << leafNodes.size() << '\n';
    vector<bool> visited(N + 2, false);
    
    for(int i : leafNodes){
    	vector<int> path;
    	int curNode = i;
    	while(!visited[curNode]){
    		visited[curNode] = true;
    		path.push_back(curNode);
    		curNode = P[curNode];
    	}

    	reverse(path.begin(), path.end());
    	cout << path.size() << '\n';
    	for(int nodes : path){
    		cout << nodes << ' ';
    	}
    	cout << '\n';
    }
    cout << '\n';
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