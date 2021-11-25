#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int A, B, C;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> B >> C;
    cout << ((A + B + C == 180) &&(min(A, min(B, C)) > 0) ? "YES" : "NO");

    return 0;
}