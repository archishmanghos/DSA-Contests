int maxLen(vector<int>&A, int n){   
    unordered_map<int, int> mp;
    int sum = 0, ans = 0;
    for(int i = 0; i < n; i++){
        sum += A[i];
        if(mp.find(sum) != mp.end()) ans = max(ans, i - mp[sum]);
        else mp[sum] = i;
        if(sum == 0) ans = max(ans, i + 1);
    }
    
    return ans;
}