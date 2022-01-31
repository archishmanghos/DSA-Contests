#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int powerOf2(int N) {
    int x = 1;
    while (x * 2 < N) {
        x <<= 1;
    }

    return x - 1;
}

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    int x = powerOf2(N);
    for (int i = 0; i < x; i++) {
        A[i] = i + 1;
    }
    A[x] = 0;
    for (int i = x + 1; i < N; i++) {
        A[i] = i;
    }

    for (int i = 0; i < N; i++) {
        cout << A[i] << ' ';
    }
    cout << '\n';
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