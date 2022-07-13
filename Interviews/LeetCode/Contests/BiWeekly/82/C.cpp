long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
    priority_queue<pair<int, int>> pq;
    map<int, int> mp;
    for(int i = 0; i < nums1.size(); i++) mp[abs(nums1[i] - nums2[i])] += 1;
    for(auto i : mp) {
        pq.push({i.first, i.second});
    }
    int k = k1 + k2;
    
    while(pq.size() > 1){
        if(k == 0) break;
        pair<int, int> greatest = pq.top();
        pq.pop();
        pair<int, int> nextGreatest = pq.top();
        pq.pop();
        int maxToClear = (greatest.first - nextGreatest.first) * greatest.second;
        if(maxToClear <= k){
            nextGreatest.second += greatest.second;
            pq.push(nextGreatest);
            k -= maxToClear;
        }else{
            int toChange = k / greatest.second;
            if(greatest.first - toChange <= nextGreatest.first){
                toChange = (greatest.first - nextGreatest.first);
                nextGreatest.second += greatest.second;
                k -= toChange * greatest.second;
                pq.push(nextGreatest);
            }else{
                greatest.first -= toChange;
                int extra = k % greatest.second;
                greatest.second -= extra;
                pq.push(greatest);
                if(greatest.first - 1 == nextGreatest.first) pq.push({greatest.first - 1, extra + nextGreatest.second});
                else pq.push({greatest.first - 1, extra}), pq.push(nextGreatest);
                k = 0;
            }
        }
    }
    
    if(k > 0){
        pair<int, int> greatest = pq.top();
        if(greatest.first * greatest.second <= k) return 0;
        int toChange = k / greatest.second;
        greatest.first -= toChange;
        int extra = k % greatest.second;
        greatest.second -= extra;
        pq.pop();
        pq.push(greatest);
        pq.push({greatest.first - 1, extra});
    }
    
    long long ans = 0;
    while(!pq.empty()){
        pair<int, int> greatest = pq.top();
        pq.pop();
        ans += 1LL * greatest.first * greatest.first * greatest.second;
    }
    
    return ans;
}