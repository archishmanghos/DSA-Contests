#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, K, A[mxN];

void solve()
{
    cin >> N >> K;
    for(int i = 1; i <= N; i++)
    	cin >> A[i];

    int i = 1, j = 1, sumTillNow = 0;
    pair<int, int> ans = {0, -1};
    while(j <= N)
    {
    	if((sumTillNow + A[j]) >= -K)
    	{
    		sumTillNow += A[j];
	    	if(ans.second - ans.first + 1 < (j - i + 1))
	    		ans = {i, j};
    		j += 1;
    	}
    	else
    	{
    		i += 1;
    		if(i <= j)
    			sumTillNow -= A[i - 1];
    	}
    	j = max(j, i);
    }

    if(ans.first != 0)
    	cout << ans.first << ' ' << ans.second << '\n';
    else
    	cout << -1 << '\n';
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