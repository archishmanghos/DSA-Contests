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
    int N;
    string S;
    cin >> N >> S;

    if (S[0] == '0' or S[1] == '0' or S[N] == '0') {
        cout << "No" << '\n';
        return;
    }

    cout << "Yes" << '\n';
    vector<int> ans(N + 2);
    for (int i = 0; i < N; i++) {
        ans[i] = i;
    }

    debug(ans)
    for (int i = 2; i < N; i++) {
        if (S[i] == '0') {
            swap(ans[i], ans[i - 1]);
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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