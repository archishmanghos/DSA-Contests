string largestWordCount(vector<string>& messages, vector<string>& senders) {
    string ans = "";
    int maxCount = 0;
    map<string, int> mp;
    
    for(int i = 0; i < senders.size(); i++){
        int countWords = 1;
        for(int j = 0; j < messages[i].size(); j++){
            if(messages[i][j] == ' ') countWords += 1;
        }
        
        mp[senders[i]] += countWords;
    }
    
    for(auto i : mp){
        if(i.second > maxCount){
            maxCount = i.second;
            ans = i.first;
        }else if(i.second == maxCount) ans = max(ans, i.first);
    }
    
    return ans;
}