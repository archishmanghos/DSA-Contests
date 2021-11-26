#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, one;

void solve()
{
    cin >> N >> one;
    if(one >= (N / 2))
    	cout << N - one << '\n';
    else
    {
    	if(one == 0)
    	{
    		cout << N *(N + 1) / 2 << '\n';
    		return;
    	}
    	int zero = N - one;
    	int div = zero / (one + 1);
    	int rem = zero - div * (one + 1);
    	div += 1;
    	int rem2 = one - rem + 1;
    	int ans = (div * (div + 1) / 2) * rem + rem2 * (div * (div - 1) / 2);
    	cout << ans << '\n';
    }
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