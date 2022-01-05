#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, X, Y;

void solve()
{
    cin >> N >> X >> Y;
    int centreX = (N + 1) / 2, centreY = (N + 1) / 2;
    int sum = abs(X - centreX) + abs(Y - centreY);
    cout << (sum & 1 ? 1 : 0) << '\n';
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