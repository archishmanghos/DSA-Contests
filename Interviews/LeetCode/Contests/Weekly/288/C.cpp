int maximumProduct(vector<int> &nums, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i : nums){
        pq.push(i);
    }
    
    long long ans = 1;
    while(k > 0){
        int topEl = pq.top();
        pq.pop();
        topEl += 1;
        pq.push(topEl);
        k -= 1;
    }
    
    int mod = 1e9 + 7;
    while(!pq.empty()){
        int topEl = pq.top();
        ans = ((ans % mod) * (topEl % mod)) % mod;
        pq.pop();
    }
    
    return ans;
}