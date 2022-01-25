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

    int toMultiply = 1;
    for(int i = 1; i <= N; i++)
    {
    	while(A[i] % 2 == 0)
    	{
    		toMultiply <<= 1;
    		A[i] >>= 1;
    	}
    }

    sort(A + 1, A + N + 1);
    A[N] *= toMultiply;

    int ans = 0;
    for(int i = 1; i <= N; i++)
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