#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;
const int mod = 1e9 + 7;

int T, N, M, L, R, X;

int raisedto(int a, int b)
{
    int res = 1;
    while(b)
    {
        if(b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void solve()
{
    cin >> N >> M;
    int ans = 0;
    for(int i = 1; i <= M; i++)
    {
    	cin >> L >> R >> X;
    	ans |= X;
    }

    int power = raisedto(2, N - 1);
    power = ((power % mod) * (ans % mod)) % mod;
    cout << power << '\n';
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