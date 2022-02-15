#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N + 2), pos(N + 2, 0);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        pos[A[i]] = i;
    }

    vector<pair<int, int>> segments;
    for (int i = 1; i <= N; i++) {
        if (A[i] + 1 <= N and pos[A[i] + 1] < i) {
            segments.push_back({pos[A[i] + 1], i});
        }
        segments.push_back({i, i});
    }

    int ans = 0;
    sort(segments.begin(), segments.end());
    int start = INF, end = -1;
    for (auto i: segments) {
        if (i.first > end) {
            ans += 1;
        }
        start = min(i.first, start);
        end = max(end, i.second);
    }

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}