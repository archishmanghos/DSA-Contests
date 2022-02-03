#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e9;

set<int> divisors(int N) {
    set<int> ans;
    for (int i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            ans.insert(N / i);
            ans.insert(i);
        }
    }
    return ans;
}

int sum(set<int> div) {
    int ans = 0;
    for (int i: div) {
        ans += i;
    }
    return ans;
}

void solve() {
    int X, A, B;
    cin >> X >> A >> B;
    if (X >= A and (X * B) % A == 0) {
        int N = (X * B) / A;
        if (N > INF) {
            cout << -1 << '\n';
            return;
        }
        set<int> divisor = divisors(N);
        int sumDiv = sum(divisor);
        if (sumDiv % A == 0 and N % B == 0) {
            A = (sumDiv / A) * A;
            B = (N / B) * B;
            if (X == sumDiv and A == sumDiv and B == N) {
                cout << N << '\n';
            } else {
                cout << -1 << '\n';
            }
        } else {
            cout << -1 << '\n';
        }
    } else {
        cout << -1 << '\n';
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