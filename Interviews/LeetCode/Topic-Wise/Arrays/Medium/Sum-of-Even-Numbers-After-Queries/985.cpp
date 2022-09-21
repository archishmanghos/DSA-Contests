vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    int sum = 0;
    for (int i : nums) {
        if (i % 2 == 0) {
            sum += i;
        }
    }

    vector<int> ans(queries.size());
    for (int i = 0; i < queries.size(); i++) {
        int idx = queries[i][1], val = queries[i][0];
        if (nums[idx] % 2 == 0) {
            if (abs(val) % 2 == 0) {
                sum += val;
            } else {
                sum -= nums[idx];
            }
            nums[idx] += val;
        } else {
            nums[idx] += val;
            if (abs(val) % 2 == 1) {
                sum += nums[idx];
            }
        }

        ans[i] = sum;
    }

    return ans;
}