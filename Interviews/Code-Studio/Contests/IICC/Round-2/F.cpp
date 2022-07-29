#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <G:\DSA-Contests\archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = LLONG_MAX;

int beautyContest(int k, vector<int> &a, vector<int> &b) {
    int n = a.size();
    vector<int> diff(n);
    for (int i = 0; i < n; i++) {
        diff[i] = a[i] - b[i];
    }

    sort(diff.begin(), diff.end());
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (diff[i] > 0) {
            ans += n - i - 1;
        } else {
            int k = upper_bound(diff.begin(),
                                diff.end(), -diff[i])
                    - diff.begin();
            ans += n - k;
        }
    }

    return ans >= k;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif

    int n, m; cin >> n >> m;
    vector<int> b(n), c(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    cout << beautyContest(m, b, c);

    return 0;
}

// https://www.geeksforgeeks.org/number-of-indices-pair-such-that-element-pair-sum-from-first-array-is-greater-than-second-array/