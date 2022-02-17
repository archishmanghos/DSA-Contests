void rec(int index, int remSum, vector<int> v, vector <vector<int>> &ans, int &n, vector<int> &candidates) {
    if (remSum == 0) {
        ans.push_back(v);
        return;
    }

    for (int i = index; i < n; i++) {
        if (candidates[i] <= remSum) {
            v.push_back(candidates[i]);
            rec(i, remSum - candidates[i], v, ans, n, candidates);
            v.pop_back();
        }
    }
}

vector <vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector <vector<int>> ans;
    vector<int> v;
    int n = candidates.size();
    rec(0, target, v, ans, n, candidates);
    return ans;
}