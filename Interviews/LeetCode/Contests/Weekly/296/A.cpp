int minMaxGame(vector<int>& nums) {
    while(nums.size() > 1){
        int n = nums.size();
        n /= 2;
        vector<int> temp(n);
        for(int i = 0; i < n; i++){
            if(i & 1) temp[i] = max(nums[2 * i], nums[2 * i + 1]);
            else temp[i] = min(nums[2 * i], nums[2 * i + 1]);
        }
        nums = temp;
    }
    
    return nums[0];
}