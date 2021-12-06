#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N;
vector<pair<int, int>> A(mxN);

int cntSatisfied(int mid)
{
	int ans = 0;
	for(int j = 1; j <= N; j++)
		ans += (A[j].first >= (mid - (ans + 1)) && A[j].second >= ans);

	return ans;
}

void solve()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    	cin >> A[i].first >> A[i].second;

    int lb = 1, ub = N, ans = 1;
    while(lb <= ub)
    {
    	int mid = lb + (ub - lb) / 2;
    	if(cntSatisfied(mid) >= mid)
    	{
    		ans = max(ans, mid);
    		lb = mid + 1;
    	}
    	else
    		ub = mid - 1;
    }

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