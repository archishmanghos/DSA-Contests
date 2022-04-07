int threeSumMulti(vector<int> &arr, int target){
    vector<long> cnt(105, 0);
    for(int i : arr){
        cnt[i] += 1;
    }
    
    long ans = 0;
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            if(cnt[i] and cnt[j]){
                int k = target - i - j;
                if(k >= 0 and k <= 100 and cnt[k]){
                    if(i == j and j == k){
                        ans += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
                    }else if(i == j and j != k){
                        ans += cnt[i] * (cnt[i] - 1) / 2 * cnt[k];
                    }else if(i < j and j < k){
                        ans += cnt[i] * cnt[j] * cnt[k];
                    }
                }
            }
        }
    }
    
    return ans % int(1e9 + 7);
}