vector<int> pivotArray(vector<int> &nums, int pivot) {
    vector<int> temp, ans;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < pivot) {
            temp.push_back(nums[i]);
        }
    }
    for (int i = 0; i < temp.size(); i++) {
        ans.push_back(temp[i]);
    }
    temp.clear();

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == pivot) {
            temp.push_back(nums[i]);
        }
    }
    for (int i = 0; i < temp.size(); i++) {
        ans.push_back(temp[i]);
    }

    temp.clear();
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > pivot) {
            temp.push_back(nums[i]);
        }
    }
    for (int i = 0; i < temp.size(); i++) {
        ans.push_back(temp[i]);
    }

    return ans;
}