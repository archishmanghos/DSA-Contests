int countPrefixes(vector<string> &words, string s){
    int ans = 0;
    for(string s1 : words){
        if(s1.size() > s.size()){
            continue;
        }
        
        bool ok = true;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s[i]){
                ok = false;
                break;
            }
        }
        
        ans += ok == true;
    }
    
    return ans;
}