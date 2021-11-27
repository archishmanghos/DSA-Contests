#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;
const int MOD = 998244353;

int T, N;

int pow(int a, int b, int m = MOD)
{
	int ans = 1;
	while(b)
	{
		if(b & 1)
			ans = (ans *a) % m;
		b /= 2;
		a = (a *a) % m;
	}
	return ans;
}

int modinv(int k)
{
	return pow(k, MOD - 2, MOD);
}

void solve()
{
    cin >> N;
    int ans = ((N * (N + 1)) % MOD * (N + 1)) % MOD;
    ans = ((ans % MOD) * (modinv(4))) % MOD;

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