#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, L, K, cache[505][505];
vector<pair<int, int>> A(505);

int dp(int index, int k)
{
	if(index == N + 1)
		return 0;

	int &ans = cache[index][k];
	if(ans != -1)
		return ans;

	ans = INF;
	for(int i = 0; i <= k; i++)
		if(index + i + 1 <= N + 1)
			ans = min(ans, dp(index + i + 1, k - i) + (A[index + i + 1].first - A[index].first) * A[index].second);

	return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> L >> K;
    for(int i = 1; i <= N; i++)
    	cin >> A[i].first;
    for(int i = 1; i <= N; i++)
    	cin >> A[i].second;
    A[N + 1].first = L;
    memset(cache, -1, sizeof(cache));

    cout << dp(1, K);

    return 0;
}