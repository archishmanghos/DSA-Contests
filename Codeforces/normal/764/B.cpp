#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, A, B, C;

void solve()
{
    cin >> A >> B >> C;
    if((2 * B - C) % A == 0 and (2 * B - C) / A > 0)
    	cout << "YES" << '\n';
    else if((A + C) % (2 * B) == 0 and (A + C) / (2 * B) > 0)
    	cout << "YES" << '\n';
    else if((2 * B - A) % C == 0 and (2 * B - A) / C > 0)
    	cout << "YES" << '\n';
    else
    	cout << "NO" << '\n';

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