#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, U, V;
set<int> adj[mxN];

void solve()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    	adj[i].clear();

    map<pair<int, int>, int> mp;
    for(int i = 1; i <= N - 1; i++)
    {
    	cin >> U >> V;
    	adj[U].insert(V);
    	adj[V].insert(U);
    	mp[ {U, V}] = i;
    	mp[ {V, U}] = i;
    }

    int leaf = -1, cnt = 0;
    for(int i = 1; i <= N; i++)
    {
    	if(adj[i].size() == 1)
    	{
    		leaf = i;
    		break;
    	}
    }

    set<int> visited;
    vector<int> ans(N + 2);
    while(visited.size() < N)
    {
    	if(adj[leaf].size() == 1)
    	{
    		int pre = leaf;
    		leaf = *adj[leaf].begin();
    		adj[pre].erase(leaf);
    		adj[leaf].erase(pre);
    		ans[mp[ {pre, leaf}]] = (cnt % 2 == 0 ? 2 : 3);
    		cnt += 1;
    		visited.insert(pre);
    	}
    	else if(adj[leaf].size() == 0)
    		visited.insert(leaf);
    	else
    	{
    		cout << -1 << '\n';
    		return;
    	}
    }

    for(int i = 1; i <= N - 1; i++)
    	cout << ans[i] << ' ';
    cout << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
        solve();

    return 0;
}