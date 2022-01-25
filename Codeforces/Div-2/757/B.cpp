#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N;
vector<pair<int, int>> A(mxN);

void solve()
{
    cin >> N;
    vector<int> occurence(N + 5, 0);
    for(int i = 1; i <= N; i++)
    {
    	cin >> A[i].first;
    	A[i].second = i;
    	occurence[i] = A[i].first;
    }

    sort(A.begin() + 1, A.begin() + N + 1);
    int ans[N + 5];
    ans[0] = 0;

    int j = 1;
    for(int i = N; i > 1; i -= 2)
    {
    	ans[A[i].second] = j;
    	ans[A[i - 1].second] = -j;
    	j += 1;
    }

    if(N & 1)
    	ans[A[1].second] = j;
    int printAns = 0;
    for(int i = 0; i <= N; i++)
    	printAns += occurence[i] * (2 * abs(ans[i]));

    cout << printAns << '\n';
    for(int i = 0; i <= N; i++)
    	cout << ans[i] << ' ';
    cout << '\n';
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