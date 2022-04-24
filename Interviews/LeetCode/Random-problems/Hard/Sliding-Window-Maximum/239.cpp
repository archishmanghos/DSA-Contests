vector<int> maxSlidingWindow(vector<int> &nums, int k){
    vector<int> ans;
    set<int> s;
    unordered_map<int, int> cnt;
    for(int i = 0; i < k; i++){
        s.insert(nums[i]);
        cnt[nums[i]] += 1;
    }
    
    ans.push_back(*s.rbegin());
    for(int i = k; i < nums.size(); i++){
        cnt[nums[i - k]] -= 1;
        if(cnt[nums[i - k]] == 0){
            s.erase(nums[i - k]);
        }
        s.insert(nums[i]);
        cnt[nums[i]] += 1;
        ans.push_back(*s.rbegin());
    }
    
    return ans;
}