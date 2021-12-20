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
    int N = S.size();

    if(N & 1)
    {
    	cout << "NO" << '\n';
    	return;
    }

    string ans1 = S.substr(0, N / 2);
    string ans2 = S.substr(N / 2);
    cout << (ans1 == ans2 ? "YES" : "NO") << '\n';
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