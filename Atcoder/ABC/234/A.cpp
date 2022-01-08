#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    int ans1 = T * T + 2 * T + 3;
    ans1 += T;
    int ans2 = T * T + 2 * T + 3;
    ans2 = ans2 * ans2 + 2 * ans2 + 3;
    // cout << ans1 << '\n';
    ans1 = ans1 * ans1 + 2 * ans1 + 3;
    ans1 += ans2;
    // cout << ans1 << '\n';
    ans1 = ans1 * ans1 + 2 * ans1 + 3;
    

    cout << ans1;


    return 0;
}