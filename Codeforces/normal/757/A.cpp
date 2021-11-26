#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, L, R, K, A[mxN];

void solve()
{
    cin >> N >> L >> R >> K;
    for(int i = 1; i <= N; i++)
    	cin >> A[i];
    sort(A + 1, A + N + 1);

    int ans = 0;
    for(int i = 1; i <= N; i++)
    {
    	if(A[i] >= L && A[i] <= R)
    	{
    		if(A[i] <= K)
    		{
    			ans += 1;
    			K -= A[i];
    		}
    	}
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