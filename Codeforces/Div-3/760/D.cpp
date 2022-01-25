#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, K, A[mxN];

void solve()
{
    cin >> N >> K;
    for(int i = 1; i <= N; i++)
    	cin >> A[i];

    int ans = 0, K1 = K;
    sort(A + 1, A + N + 1);

    for(int i = N; i > (N - K); i--)
    	ans += A[i - K] / A[i];
    for(int i = (N - 2 * K); i >= 1; i--)
    	ans += A[i];

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