#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, A[mxN], cache[mxN];

int dp(int index)
{
	if(index > N)
		return INF;
	if(index == N)
		return 0;
	if(cache[index] != -1)
		return cache[index];

	int ans = INF;
	for(int i = index + 1; i <= N; i++)
	{
		int cost = ((i - index + 1) * A[index]) - A[i];
		ans = min(ans, dp(i) + cost);
	}
	return cache[index] = ans;
}

void solve()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    	cin >> A[i];

    memset(cache, -1, sizeof(cache));
    int ans = dp(1);
    cout << max((int)0, ans) << '\n';
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