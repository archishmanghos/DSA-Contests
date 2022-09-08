void subsetGenerator(int index, vector<int> curSubset, vector<vector<int>> &ans, vector<int> &nums){
    ans.push_back(curSubset);
    for(int i = index; i < nums.size(); i++){
        if(i > index and nums[i] == nums[i - 1]) continue;
        curSubset.push_back(nums[i]);
        subsetGenerator(i + 1, curSubset, ans, nums);
        curSubset.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    subsetGenerator(0, {}, ans, nums);
    return ans;
}