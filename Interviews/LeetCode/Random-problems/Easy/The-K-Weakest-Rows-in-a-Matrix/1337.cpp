vector<int> kWeakestRows(vector<vector<int>> &mat, int k){
    int n = mat.size(), m = mat[0].size();
    for(int i = 0; i < n; i++){
        mat[i].push_back(i);
    }
    
    sort(mat.begin(), mat.end());
    vector<int> ans;
    for(int i = 0; i < k; i++){
        ans.push_back(mat[i][m]);
    }
    
    return ans;
}