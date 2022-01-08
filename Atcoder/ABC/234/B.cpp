#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int N;
vector<pair<int, int>> A(105);

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 1; i <= N; i++)
    	cin >> A[i].first >> A[i].second;

    double ans = -INF;
    for(int i = 1; i <= N; i++)
    {
    	for(int j = 1; j <= N and j != i; j++)
    	{
    		int dist = (A[i].first - A[j].first) * (A[i].first - A[j].first) + (A[i].second - A[j].second) * (A[i].second - A[j].second);
    		double distt = sqrt((double)dist);
    		ans = max(ans, distt);
    	}
    }

    cout << fixed << setprecision(9) << ans;

    return 0;
}