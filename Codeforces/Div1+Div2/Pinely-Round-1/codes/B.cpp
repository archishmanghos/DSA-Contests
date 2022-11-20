#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n <= 2) {
        cout << n << '\n';
        return;
    }

    bool ok = true;
    for (int i = 0; i < n - 2; i++) {
        ok &= a[i] == a[i + 2];
    }

    cout << (ok ? n - (n - 2) / 2 : n) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}