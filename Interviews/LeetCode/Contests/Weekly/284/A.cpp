vector<int> findKDistantIndices(vector<int> &nums, int key, int k){
    set<int> ans;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == key){
            for(int j = 0; j < nums.size(); j++){
                if(abs(i - j) <= k){
                    ans.insert(j);
                }
            }
        }
    }
    vector<int> finalAns;
    for(int i : ans){
        finalAns.push_back(i);
    }
    return finalAns;
}