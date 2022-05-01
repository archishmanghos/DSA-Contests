vector<vector<int>> generate(int numRows){
    vector<vector<int>> ans(numRows);
    
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j <= i; j++){
            if(i > 0 and j > 0){
                ans[i].push_back((ans[i - 1].size() > j ? ans[i - 1][j - 1] + ans[i - 1][j] : 1));
            }else{
                ans[i].push_back(1);
            }
        }
    }
    
    return ans;
}