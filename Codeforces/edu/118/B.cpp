#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, A[mxN];

void solve()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    	cin >> A[i];

    sort(A + 1, A + N + 1);
    for(int i = N; i > (N + 1) / 2; i--)
    	cout << A[i] << ' ' << A[1] << '\n';
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