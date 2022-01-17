#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N;
vector<pair<int, int>> A(105);

void solve()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    	cin >> A[i].first;
    for(int i = 1; i <= N; i++)
    	cin >> A[i].second;

    int ans = 0, lastIndex = A[N].first, startIndex = -1;
    for(int i = N; i > 1; i--)
    {
    	if(startIndex == -1)
    		startIndex = A[i].first - A[i].second + 1;
    	else
    		startIndex = min(startIndex, A[i].first - A[i].second + 1);
    	if(A[i].first - A[i - 1].first >= A[i].second)
    	{
    		if(startIndex > A[i - 1].first)
    		{
    			int add = lastIndex - startIndex + 1;
    			ans += add * (add + 1) / 2;
    			lastIndex = A[i - 1].first;
    		}
    	}
    }

    if(startIndex == -1)
		startIndex = A[1].first - A[1].second + 1;
	else
		startIndex = min(startIndex, A[1].first - A[1].second + 1);
    int add = lastIndex - startIndex + 1;
    ans += add * (add + 1) / 2;

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