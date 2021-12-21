#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, M;

void solve()
{
    cin >> M >> N;
    vector<vector<int>> A(M + 2, vector<int>(N + 2));
    vector<int> v(N + 2, 0);
    for(int i = 1; i <= M; i++)
    	for(int j = 1; j <= N; j++)
    		cin >> A[i][j];

    if(N - 1 >= M)
    {
    	for(int i = 1; i <= N; i++)
    		for(int j = 1; j <= M; j++)
    			v[i] = max(v[i], A[j][i]);
    }
    else
    {
    	pair<pair<int, int>, pair<int, int>>finalMaxx = {{0, 0}, {-1, -1}};
    	for(int i = 1; i <= M; i++)
    	{
    		pair<int, int> maxx = {0, -1}, secondMaxx = {0, -1};
    		for(int j = 1; j <= N; j++)
    		{
    			if(A[i][j] > maxx.first)
    				maxx = {A[i][j], j};
    		}
    		for(int j = 1; j <= N; j++)
    		{
    			if(A[i][j] > secondMaxx.first && j != maxx.second)
    				secondMaxx = {A[i][j], j};
    		}

    		if(min(maxx.first, secondMaxx.first) > min(finalMaxx.first.first, finalMaxx.first.second))
    			finalMaxx = {{maxx.first, secondMaxx.first}, {maxx.second, secondMaxx.second}};
    	}

    	v[finalMaxx.second.first] = finalMaxx.first.first;
    	v[finalMaxx.second.second] = finalMaxx.first.second;

    	for(int i = 1; i <= N; i++)
    	{
    		if(i == finalMaxx.second.first or i == finalMaxx.second.second)
    			continue;
    		for(int j = 1; j <= M; j++)
    			v[i] = max(v[i], A[j][i]);
    	}
    }

    int ans = INF;
	for(int i = 1; i <= N; i++)
		ans = min(ans, v[i]);
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