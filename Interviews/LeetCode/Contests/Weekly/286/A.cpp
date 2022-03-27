vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2){
    set<int> s1, s2;
    for(int i : nums1){
        s1.insert(i);
    }
    for(int i : nums2){
        s2.insert(i);
    }
    
    vector<vector<int>> ans(2);
    for(int i : s1){
        if(s2.find(i) == s2.end()){
            ans[0].push_back(i);
        }
    }
    
    for(int i : s2){
        if(s1.find(i) == s1.end()){
            ans[1].push_back(i);
        }
    }
    
    return ans;
}