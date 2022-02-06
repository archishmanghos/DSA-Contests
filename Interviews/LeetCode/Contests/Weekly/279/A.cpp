vector<int> sortEvenOdd(vector<int> &nums) {
    vector<int> odd, even;
    for (int i = 0; i < nums.size(); i++) {
        if (i & 1) {
            odd.push_back(nums[i]);
        } else {
            even.push_back(nums[i]);
        }
    }
    sort(odd.begin(), odd.end(), greater<int>());
    sort(even.begin(), even.end());
    vector<int> ans;
    int i = 0, j = 0, cnt = 0;
    while (cnt < nums.size()) {
        if (cnt & 1) {
            ans.push_back(odd[j++]);
        } else {
            ans.push_back(even[i++]);
        }
        cnt += 1;
    }

    return ans;
}