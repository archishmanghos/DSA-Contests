#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, A[mxN];

void solve() {

    cin >> N;
    int sum = 0, minNum = INF;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        sum += A[i];
        minNum = min(minNum, A[i]);
    }

    int maxDiv = 0;
    for (int i = 1; i * i <= sum; i++) {
        if (sum % i == 0) {
            if (sum / i < minNum)
                maxDiv = max(maxDiv, sum / i);
            if (i < minNum)
                maxDiv = max(maxDiv, i);
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << A[i] - maxDiv << ' ';
    }
    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
        solve();

    return 0;
}