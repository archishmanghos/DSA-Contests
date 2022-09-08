int longestConsecutive(vector<int>& nums) {
    unordered_set<int> us;
    for(int i : nums) us.insert(i);
    int ans = 0;
    for(int i : nums){
        if(us.find(i - 1) != us.end()) continue;
        int cnt = 0, curNum = i;
        while(us.find(curNum) != us.end()) cnt++, curNum++;
        ans = max(ans, cnt);
    }
    
    return ans;
}