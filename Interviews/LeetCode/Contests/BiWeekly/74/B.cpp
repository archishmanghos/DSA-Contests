long long maximumSubsequenceCount(string text, string pattern){
    if(pattern[0] == pattern[1]){
        long long count = 0, ans;
        for(char c : text){
            count += c == pattern[0];
        }
        ans = count * (count + 1) / 2;
        return ans;
    }
    
    string temp1 = pattern[0] + text;
    vector<long long> count(26, 0);
    long long ans1 = 0;
    for(char c : temp1){
        if(c == pattern[1]){
            ans1 += count[pattern[0] - 'a'];
        }else if(c == pattern[0]){
            count[c - 'a'] += 1;
        }
    }
    
    string temp2 = text + pattern[1];
    count.assign(26, 0);
    long long ans2 = 0;
    for(char c : temp2){
        if(c == pattern[1]){
            ans2 += count[pattern[0] - 'a'];
        }else if(c == pattern[0]){
            count[c - 'a'] += 1;
        }
    }
    
    return max(ans1, ans2);
}