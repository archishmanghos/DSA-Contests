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
    cout << (N % 5 == 0 && N % 11 == 0 ? "BOTH" : (N % 5 == 0 || N % 11 == 0) ? "ONE" : "NONE");

    return 0;
}