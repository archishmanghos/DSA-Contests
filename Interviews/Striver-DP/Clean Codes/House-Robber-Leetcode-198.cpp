#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int prevToPrev, prev = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        int curAmount = max((i > 1 ? prevToPrev : 0) + nums[i], prev);
        prevToPrev = prev, prev = curAmount;
    }

    cout << prev;

    return 0;
}