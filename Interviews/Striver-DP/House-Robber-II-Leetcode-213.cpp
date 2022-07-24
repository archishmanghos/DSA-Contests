#include <bits/stdc++.h>
using namespace std;

int dp(int start, int end, vector<int> &nums) {
    int prev = 0, prevToPrev = 0;
    for (int i = end - 1; i >= start; i--) {
        int curMax = max(prevToPrev + nums[i], prev);
        prevToPrev = prev;
        prev = curMax;
    }

    return prev;
}

int32_t main() {

    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    if (n == 1) return nums[0];
    cout << max(dp(0, n - 1, nums), dp(1, n, nums));

    return 0;
}