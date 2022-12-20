#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxn = 500500;
const int LOG = 40;
int a[mxn], cnt[LOG];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x; cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 0; j < LOG; j++) {
            if ((a[i] >> j) & 1) cnt[j] += 1;
        }
    }

    int ans = 0;
    for (int i = LOG - 1; i >= 0; i--) {
        if (cnt[i] < (n + 1) / 2) {
            int X = ans | (1LL << i);
            if (X <= x) ans = X;
        }
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) sum += (ans ^ a[i]);
    cout << sum;

    return 0;
}