#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, sum;

void solve()
{
    cin >> N >> sum;
    if(sum % 2 == 0)
    	cout << (N == 1 ? "Even" : "Impossible") << '\n';
    else
    	cout << (N % 2 ? "Odd" : "Even") << '\n';
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