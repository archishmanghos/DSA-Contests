#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, ans = 1, INF = 1e18;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            cout << 0 << '\n';
            return 0;
        }
        if (ans > INF / a[i]) {
            cout << -1;
            return 0;
        }
        ans *= a[i];
    }
    cout << ans;
    return 0;
}