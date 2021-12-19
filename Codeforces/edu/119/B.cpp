#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, W, H, A, K;

void solve()
{
    cin >> W >> H;
    int ans = 0;
    for(int i = 1; i <= 4; i++)
    {
    	cin >> K;
    	int maxDist = 0, minn;
    	cin >> minn;
    	for(int j = 2; j <= K; j++)
    	{
    		cin >> A;
    		maxDist = max(maxDist, A - minn);
    	}
    	if(i <= 2)
    		ans = max(ans, H *maxDist);
    	else
    		ans = max(ans, W *maxDist);
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