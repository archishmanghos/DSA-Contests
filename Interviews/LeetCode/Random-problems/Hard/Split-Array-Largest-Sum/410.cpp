int splitArray(vector<int> &nums, int m){
    int sum = 0, maxx = nums[0];
    for(int i : nums){
        sum += i;
        maxx = max(maxx, i);
    }
    
    int low = maxx, high = sum, ans;
    while(low <= high){
        int mid = low + (high - low) / 2;
        int minSubarrays = 1, sum = 0;
        for(int i : nums){
            sum += i;
            if(sum > mid){
                minSubarrays += 1;
                sum = i;
            }
        }
        if(minSubarrays <= m){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    
    return ans;
}