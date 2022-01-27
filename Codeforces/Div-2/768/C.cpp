#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> a, b;
    for (int i = 0; i < N / 2; i++) {
        a.push_back(i);
    }
    for (int i = N - 1; i >= N / 2; i--) {
        b.push_back(i);
    }

    if (K < N / 2) {
        swap(b[0], b[K]);
        vector<pair<int, int>> v;
        for (int i = 0; i < a.size(); i++) {
            v.push_back({a[i], b[i]});
        }
        for (auto i: v) {
            cout << i.first << ' ' << i.second << '\n';
        }
    } else if (K == N / 2) {
        swap(a[N / 2 - 1], b[0]);
        vector<pair<int, int>> v;
        for (int i = 0; i < a.size(); i++) {
            v.push_back({a[i], b[i]});
        }
        for (auto i: v) {
            cout << i.first << ' ' << i.second << '\n';
        }
    } else if (K > N / 2 and K < N - 1) {
        swap(a[N / 2 - 1], b[0]);
        swap(b[0], b[K - N / 2]);
        vector<pair<int, int>> v;
        for (int i = 0; i < a.size(); i++) {
            v.push_back({a[i], b[i]});
        }
        for (auto i: v) {
            cout << i.first << ' ' << i.second << '\n';
        }
    } else {
        if (N == 4) {
            cout << -1 << '\n';
        } else {
            swap(a[N / 2 - 1], b[0]);
            swap(a[N / 4 - 1], a[N / 4]);
            vector<pair<int, int>> v;
            for (int i = 0; i < a.size(); i++) {
                v.push_back({a[i], b[i]});
            }
            for (auto i: v) {
                cout << i.first << ' ' << i.second << '\n';
            }
        }
    }
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