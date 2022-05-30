void combinations(int index, int target, vector<int> curSubset, vector<vector<int>> &ans, vector<int> &candidates){
    if(target == 0){
        ans.push_back(curSubset);
        return;
    }
    
    if(index == candidates.size()){
        return;
    }
    
    combinations(index + 1, target, curSubset, ans, candidates);
    while(candidates[index] <= target){
        curSubset.push_back(candidates[index]);
        target -= candidates[index];
        combinations(index + 1, target, curSubset, ans, candidates);
    }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target){
    vector<vector<int>> ans;
    combinations(0, target, {}, ans, candidates);
    return ans;
}