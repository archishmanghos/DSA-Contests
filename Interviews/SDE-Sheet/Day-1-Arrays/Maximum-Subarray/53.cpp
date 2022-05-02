int maxSubArray(vector<int> &nums){
    int ans = -100000, sumTillNow = 0;
    for(int i : nums){
        sumTillNow += i;
        ans = max(ans, sumTillNow);
        if(sumTillNow < 0){
            sumTillNow = 0;
        }
    }
    
    return ans;
}