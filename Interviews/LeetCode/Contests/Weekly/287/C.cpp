int maximumCandies(vector<int> &candies, long long k){
    long long ans = 0, sum = 0;
    for(int i : candies){
        sum += i;
    }
    long long low = 0, high = sum;
    while(low <= high){
        long long mid = low + (high - low) / 2;
        
        if(mid == 0){
            ans = max(ans, mid);
            low = mid + 1;
            continue;
        }
        
        long long piles = 0;
        
        for(int i : candies){
            piles += (i / mid);
        }
        if(piles >= k){
            ans = max(ans, mid);
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    
    return ans;
}