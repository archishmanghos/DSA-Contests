int minDeletion(vector<int> &nums){
    int i = 0, ans = 0;
    while(i < nums.size()){
        int effectiveIndex = i - ans;
        if(effectiveIndex % 2 == 0){
            if(i + 1 < nums.size() and nums[i] == nums[i + 1]){
                ans += 1;
            }
        }
        i += 1;
    }
    
    int remains = (int)nums.size() - ans;
    ans += (remains % 2 == 1);
    
    return ans;
}