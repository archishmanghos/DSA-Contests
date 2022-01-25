#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, M, R, C;
char A[55][55];

void solve()
{
    cin >> N >> M >> R >> C;
    bool black = false;
    for(int i = 1; i <= N; i++)
    {
    	for(int j = 1; j <= M; j++)
    	{
    		cin >> A[i][j];
    		black |= A[i][j] == 'B';
    	}
    }

    if(A[R][C] != 'B')
    {
    	if(!black)
    		cout << -1 << '\n';
    	else
    	{
    		bool ok = false;
    		for(int i = 1; i <= M; i++)
    			ok |= A[R][i] == 'B';
    		for(int i = 1; i <= N; i++)
    			ok |= A[i][C] == 'B';

    		if(ok)
    			cout << 1 << '\n';
    		else
    			cout << 2 << '\n';
    	}
    }
    else
    	cout << 0 << '\n';
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