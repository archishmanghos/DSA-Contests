vector<vector<int>> fourSum(vector<int>& nums, int target) {
    if(nums.size() < 4) return {};
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for(int i = 0; i < nums.size() - 3; i++){
        int remTarget1 = target - nums[i];
        for(int j = i + 1; j < nums.size() - 2; j++){
            int remTarget2 = remTarget1 - nums[j], k = j + 1, l = nums.size() - 1;
            while(k < l){
                int curSum = nums[k] + nums[l];
                if(curSum > remTarget2) l--;
                else if(curSum < remTarget2) k++;
                else{
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    int num1 = nums[k], num2 = nums[l];
                    while(k < l and nums[k] == num1) k++;
                    while(k < l and nums[l] == num2) l--;
                }
            }

            while(j + 1 < nums.size() and nums[j] == nums[j + 1]) j++;
        }
        while(i + 1 < nums.size() and nums[i] == nums[i + 1]) i++;
    }
    
    return ans;
}