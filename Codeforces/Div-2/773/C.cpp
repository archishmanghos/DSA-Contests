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
    int N, X;
    cin >> N >> X;
    vector<int> A(N + 2);
    unordered_map<int, int> cnt;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        cnt[A[i]] += 1;
    }

    sort(A.begin() + 1, A.begin() + N + 1);
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (cnt[A[i]]) {
            if (cnt.find(X * A[i]) != cnt.end()) {
                if (cnt[X * A[i]] > 0) {
                    cnt[X * A[i]] -= 1;
                } else {
                    ans += 1;
                }
            } else {
                ans += 1;
            }
            cnt[A[i]] -= 1;
        }
    }

    cout << ans << '\n';
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