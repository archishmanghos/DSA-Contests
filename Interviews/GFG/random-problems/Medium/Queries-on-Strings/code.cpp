vector<int>SolveQueris(string str, vector<vector<int>>Query){
    int n = str.size();
    vector<vector<int>> prefSum(n, vector<int>(26, 0));
    
    for(int i = 0; i < n; i++){
        prefSum[i][str[i] - 'a'] = 1;
        for(int j = 0; j < 26; j++){
            prefSum[i][j] += (i > 0 ? prefSum[i - 1][j] : 0);
        }
    }
    
    vector<int> ans;
    for(auto i : Query){
        int l = i[0] - 1, r = i[1] - 1;
        int cntDistinct = 0;
        for(int j = 0; j < 26; j++){
            int cntRem = prefSum[r][j] - (l > 0 ? prefSum[l - 1][j] : 0);
            cntDistinct += cntRem > 0;
        }
        ans.push_back(cntDistinct);
    }
    
    return ans;
}