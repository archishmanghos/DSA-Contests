#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

struct store {
    int index;
    vector<int> v1, v2;
};

int N;
vector<int> A(105), B(105);
int cache[105][10005];

int dp(int index, int sumA, int &totalSum) {
    if (index > N) {
        return sumA * sumA + (totalSum - sumA) * (totalSum - sumA);
    }

    int &ans = cache[index][sumA];
    if (ans != -1) {
        return cache[index][sumA];
    }

    ans = min(dp(index + 1, sumA + A[index], totalSum), dp(index + 1, sumA + B[index], totalSum));
    return ans;
}

void solve() {
    cin >> N;

    int totalSum = 0, sqSum = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        totalSum += A[i];
        sqSum += (A[i] * A[i]);
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
        totalSum += B[i];
        sqSum += (B[i] * B[i]);
    }

    memset(cache, -1, sizeof(cache));
    int ans = dp(1, 0, totalSum) + (N - 2) * sqSum;
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