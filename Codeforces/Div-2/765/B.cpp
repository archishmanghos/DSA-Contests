#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 150005;
const int INF = 1e18 + 7;

int T, N, A[mxN];

void solve()
{
    cin >> N;
    vector<vector<int>> index(mxN);
    vector<int> visited(mxN, 0);
    int ans = -1;
    for(int i = 1; i <= N; i++)
    {
    	cin >> A[i];
    	index[A[i]].push_back(i);
    }

    for(int i = 1; i <= N; i++)
    {
    	if(visited[A[i]])
    		continue;

    	if(index[A[i]].size() == 1)
    		continue;
    	visited[A[i]] = 1;
    	for(int j = 1; j < index[A[i]].size(); j++)
    		ans = max(ans, N - index[A[i]][j] + index[A[i]][j - 1]);
    }

    cout << ans << '\n';
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