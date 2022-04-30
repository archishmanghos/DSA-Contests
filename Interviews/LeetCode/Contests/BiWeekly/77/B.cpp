int minimumAverageDifference(vector<int> &nums){
    int n = nums.size();
    vector<long long> prefSum(n, 0), suffixSum(n, 0);
    
    prefSum[0] = nums[0];
    for(int i = 1; i < n; i++){
        prefSum[i] = prefSum[i - 1] + nums[i];
    }
    
    suffixSum[n - 1] = nums[n - 1];
    for(int i = n - 2; i >= 0; i--){
        suffixSum[i] = suffixSum[i + 1] + nums[i];
    }
    
    int ans = 0;
    long long minDiff = 100000000;
    for(int i = 0; i < n; i++){
        long long left = prefSum[i] / (i + 1);
        long long right = (i < n - 1 ? suffixSum[i + 1] : 0);
        if(i < n - 1){
            right /= (n - i - 1);
        }
        int diff = abs(left - right);
        if(diff < minDiff){
            minDiff = diff;
            ans = i;
        }
    }
    
    return ans;
}