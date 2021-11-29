#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, X, K, A[mxN], B[mxN];

void solve()
{
    cin >> N >> X >> K;
    for(int i = 1; i <= N; i++)
    	cin >> A[i];

    for(int i = 1; i <= N; i++)
    	cin >> B[i];

    int ans = 0;
    for(int i = 1; i <= N; i++)
    	ans += abs(A[i] - B[i]) <= K;
    cout << (ans >= X ? "YES" : "NO") << '\n';
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