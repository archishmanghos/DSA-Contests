#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, S, A, B, C;

void solve()
{
    cin >> S >> A >> B >> C;
    bool minus = false;
    int value = abs(C);
    if(value != C)
    	minus = true;
    double change = (S / 100.0) * (double)value;
    double ans = (minus ? (double)S - change : (double)S + change);
    cout << (ans >= A &&ans <= B ? "Yes" : "No") << '\n';
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