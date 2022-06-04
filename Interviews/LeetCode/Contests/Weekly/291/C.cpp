int countDistinct(vector<int>& nums, int k, int p) {
    set<vector<int>> subArrays;
    for(int i = 0; i < nums.size(); i++){
        int cnt = 0;
        vector<int> curSubArray;
        for(int j = i; j < nums.size(); j++){
            cnt += nums[j] % p == 0;
            if(cnt <= k) curSubArray.push_back(nums[j]), subArrays.insert(curSubArray);
            else break;
        }
    }

    return int(subArrays.size());
}