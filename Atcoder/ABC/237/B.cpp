#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int H, W;
    cin >> H >> W;
    int A[H + 1][W + 1];
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 1; i <= W; i++) {
        for (int j = 1; j <= H; j++) {
            cout << A[j][i] << ' ';
        }
        cout << '\n';
    }


    return 0;
}