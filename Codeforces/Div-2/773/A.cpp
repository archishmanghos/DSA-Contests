#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <D:/archishmanghos/Practice/Online_Judges/Clion/archiDebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

void solve() {
    vector<pair<int, int>> A(3);
    for (int i = 0; i < 3; i++) {
        cin >> A[i].first >> A[i].second;
    }

    double ans = 0.0;
    if (A[0].second == A[1].second and A[2].second < A[1].second) {
        ans += abs(A[0].first - A[1].first);
    } else if (A[1].second == A[2].second and A[0].second < A[1].second) {
        ans += abs(A[2].first - A[1].first);
    } else if (A[0].second == A[2].second and A[1].second < A[0].second) {
        ans += abs(A[0].first - A[2].first);
    }

    cout << fixed << setprecision(9) << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}