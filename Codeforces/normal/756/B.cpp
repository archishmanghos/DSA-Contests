#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, A, B;

void solve()
{
	cin >> A >> B;
	if(A < B)
		swap(A, B);

	int ans = (A + B) / 4;
	if(ans < B)
		cout << ans << '\n';
	else
		cout << B << '\n';
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