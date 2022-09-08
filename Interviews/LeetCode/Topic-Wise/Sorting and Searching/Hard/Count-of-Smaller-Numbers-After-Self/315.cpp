void merge(int l, int mid, int r, vector<pair<int, int>> &nums, vector<int> &cnt) {
    vector<pair<int, int>> ans;
    int i = l, j = mid + 1, countLess = 0;
    while (i <= mid and j <= r) {
        if (nums[i].first <= nums[j].first) {
            ans.push_back(nums[i]);
            cnt[nums[i].second] += countLess;
            i += 1;
        }
        else {
            ans.push_back(nums[j]);
            countLess += 1;
            j += 1;
        }
    }

    while (i <= mid) {
        ans.push_back(nums[i]);
        cnt[nums[i].second] += countLess;
        i += 1;
    }

    while (j <= r) {
        ans.push_back(nums[j]);
        j += 1;
    }

    for (int i = l; i <= r; i++) {
        nums[i] = ans[i - l];
    }
}
void mergeSort(int l, int r, vector<pair<int, int>>& nums, vector<int> &cnt) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    mergeSort(l, mid, nums, cnt);
    mergeSort(mid + 1, r, nums, cnt);
    merge(l, mid, r, nums, cnt);
}
vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n), cnt(n, 0);
    vector<pair<int, int>> numsIndex;
    for (int i = 0; i < n; i++) {
        numsIndex.push_back({nums[i], i});
    }
    mergeSort(0, nums.size() - 1, numsIndex, cnt);
    for (int i = 0; i < numsIndex.size(); i++) {
        ans[numsIndex[i].second] = cnt[numsIndex[i].second];
    }

    return ans;
}