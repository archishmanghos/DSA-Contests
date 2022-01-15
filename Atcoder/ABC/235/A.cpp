#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

char a, b, c;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c;
    int ans = (a - '0') * 100 + (b - '0') * 10 + (c - '0');
    ans += (a - '0') + (b - '0') * 100 + (c - '0') * 10;
    ans += (a - '0') * 10 + (b - '0') + (c - '0') * 100;
    cout << ans;
    

    return 0;
}