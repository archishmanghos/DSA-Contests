vector<int> partitionLabels(string s){
    vector<int> lastIndex(26);
    for(int i = 0; i < s.size(); i++){
        lastIndex[s[i] - 'a'] = i;
    }
    
    int start = 0, end = 0;
    vector<int> ans;
    for(int i = 0; i < s.size(); i++){
        end = max(lastIndex[s[i] - 'a'], end);
        if(end == i){
            ans.push_back(end - start + 1);
            start = i + 1;
            end = i + 1;
        }
    }
    
    if(end < s.size()){
        ans.push_back(end - start + 1);
    }
    
    return ans;
}