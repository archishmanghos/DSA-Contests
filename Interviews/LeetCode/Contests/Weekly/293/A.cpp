vector<string> removeAnagrams(vector<string>& words) {
    vector<string> ans;
    string prevWord = "";
    for(string word : words){
        string temp = word;
        sort(temp.begin(), temp.end());
        if(temp == prevWord) continue;
        ans.push_back(word);
        prevWord = temp;
    }
    
    return ans;
}