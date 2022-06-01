void combinationSum(int index, int target, vector<int> curSubset, vector<int> &v, vector<vector<int>> &ans){
    if(target == 0) ans.push_back(curSubset);
    
    for(int i = index; i < v.size(); i++){
        if(i > index and v[i] == v[i - 1]) continue;
        if(v[i] > target) break;
        curSubset.push_back(v[i]);
        combinationSum(i + 1, target - v[i], curSubset, v, ans);
        curSubset.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target){
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    combinationSum(0, target, {}, candidates, ans);
    return ans;
}