int triangleNumber(vector<int>& nums) {
    if(nums.size() < 3){
        return 0;
    }
    
    sort(nums.begin(), nums.end());
    int ans = 0;
    for(int i = 2; i < nums.size(); i++){
        int j = 0, k = i - 1;
        while(j < k){
            if(nums[j] + nums[k] > nums[i]){
                ans += k - j;
                k -= 1;
            }else{
                j += 1;
            }
        }
    }
    return ans;
}