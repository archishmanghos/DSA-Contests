#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 3e5 + 5;
const int INF = 1e18 + 7;

int N, W;
vector<pair<int, int>> A(mxN);

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> W;
    for(int i = 1; i <= N; i++)
    	cin >> A[i].first >> A[i].second;

    sort(A.begin() + 1, A.begin() + N + 1);
    int ans = 0;
    for(int i = N; i >= 1; i--)
    {
    	int toTake = min(W, A[i].second);
    	W -= toTake;
    	ans += toTake * A[i].first;
    }

    cout << ans << '\n';

    return 0;
}