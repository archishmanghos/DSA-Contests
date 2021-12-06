#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, M;

void solve()
{
    cin >> N >> M;
    if(N > 1 && M > 1)
    	cout << 2 << '\n';
    else if(N + M > 2)
    	cout << 1 << '\n';
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