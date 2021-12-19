#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T;
string S;

void solve()
{
    cin >> S;
    int cnt = 0;
    for(char c : S)
    	cnt += c == 'N';
    cout << (cnt == 1 ? "NO" : "YES") << '\n';
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