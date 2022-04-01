vector<int> maxProductSubsequence(int *arr, int n){
    if(n < 3){
        return {-1};
    }
    vector<int> suffixMax(n, 0), ans = {-1};
    suffixMax[n - 1] = arr[n - 1];
    for(int i = n - 2; i >= 0; i--){
        suffixMax[i] = max(suffixMax[i + 1], arr[i]);
    }
    set<int> s;
    s.insert(arr[0]);
    long long pro = 1;
    for(int i = 2; i < n - 1; i++){
        if(*s.begin() >= arr[i]){
            s.insert(arr[i]);
            continue;
        }
        auto leftGreatest = s.lower_bound(arr[i]);
        leftGreatest--;
        int left = *leftGreatest;
        long long prod = left * 1LL * arr[i] * 1LL * suffixMax[i + 1];
        if(left < arr[i] and suffixMax[i + 1] > arr[i] and prod > pro){
            pro = prod;
            ans = {left, arr[i], suffixMax[i + 1]};
        }
        s.insert(arr[i]);
    }
    
    return ans;
} 