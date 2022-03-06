long long minimalKSum(vector<int> &nums, int k) {
    long long ans = 0;

    sort(nums.begin(), nums.end());
    long long pre = -1;
    for (long long i = 0; i < nums.size(); i++) {
        if (k > 0) {
            if (pre == -1) {
                pre = (long long) nums[i];
                if (nums[i] == 1) {
                    continue;
                } else {
                    long long terms = min((long long) k, (long long) nums[i] - 1);
                    k -= terms;
                    ans += terms + (terms * (terms - 1) / 2);
                }
            } else {
                long long terms = min((long long) k, max(0ll, (long long) nums[i] - pre - 1));
                k -= terms;
                ans += ((pre + 1) * terms) + (terms * (terms - 1) / 2);
                pre = (long long) nums[i];
            }
        } else {
            break;
        }
    }

    if (k > 0) {
        ans += ((pre + 1) * (long long) k) + ((long long) k * ((long long) k - 1) / 2);
    }
    return ans;
}