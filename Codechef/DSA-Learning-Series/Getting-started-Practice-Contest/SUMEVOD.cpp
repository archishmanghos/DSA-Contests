#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int N;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int ans1 = N * (1 + (N - 1));
    int ans2 = N * (2 + (N - 1));

    cout << ans1 << ' ' << ans2 << '\n';

    return 0;
}