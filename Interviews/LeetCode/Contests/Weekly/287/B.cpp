vector<vector<int>> findWinners(vector<vector<int>> &matches){
    vector<int> winner(100005, 0), occur(100005, 0);
    for(auto i : matches){
        winner[i[0]] += 1;
        occur[i[0]] += 1;
        occur[i[1]] += 1;
    }
    
    vector<vector<int>> ans(2);
    for(int i = 1; i <= 100000; i++){
        if(occur[i]){
            if(winner[i] == occur[i]){
                ans[0].push_back(i);
            }else if(winner[i] == (occur[i] - 1)){
                ans[1].push_back(i);
            }
        }
    }
    
    return ans;
}