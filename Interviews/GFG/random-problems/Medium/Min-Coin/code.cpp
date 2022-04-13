int dp(int amountLeft, vector<int> &nums, vector<int> &cache){
    if(amountLeft == 0){
        return 0;
    }
    if(cache[amountLeft] != -1){
        return cache[amountLeft];
    }
    
    int ans = 1e5;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] <= amountLeft){
            ans = min(ans, dp(amountLeft - nums[i], nums, cache) + 1);
        }
    }
    
    return cache[amountLeft] = ans;
}
int MinCoin(vector<int>nums, int amount)
{
    vector<int> cache(int(1e4 + 5), -1);
    int minn = nums[0];
    for(int i : nums){
        minn = min(minn, i);
    }
    minn = (amount + minn - 1) / minn;
    int ans = dp(amount, nums, cache);
    return (ans > minn ? -1 : ans);
}