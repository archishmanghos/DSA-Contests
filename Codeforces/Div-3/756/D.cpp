#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, B[mxN], P[mxN];

void solve()
{
    cin >> N;
    vector<int> ancestor(N + 5);
    for(int i = 1; i <= N; i++)
    {
    	cin >> B[i];
    	ancestor[i] = B[i];
    }

    for(int i = 1; i <= N; i++)
    	cin >> P[i];

    vector<int> dist(N + 2, -1);
    int j = 1;
    for(int i = 1; i <= N; i++)
    {
    	if(ancestor[P[i]] == P[i])
    		dist[P[i]] = 0;
    	else if(dist[ancestor[P[i]]] != -1)
    		dist[P[i]] = j++;
    	else
    	{
    		cout << -1 << '\n';
    		return;
    	}
    }

    for(int i = 1; i <= N; i++)
    	cout << (dist[i] - dist[B[i]]) << ' ';
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