void rec(int index, string s, map<int, vector<char>> &mp, vector<string> &ans, string &digits, int &n){
    if(index == n){
        ans.push_back(s);
        return;
    }
    
    for(char i : mp[digits[index] - '0']){
        s.push_back(i);
        rec(index + 1, s, mp, ans, digits, n);
        s.pop_back();
    }
}
vector<string> letterCombinations(string digits){
    map<int, vector<char>> mp;
    char c = 'a';
    for(int i = 2; i <= 6; i++){
        for(int j = 1; j <= 3; j++){
            mp[i].push_back(c++);
        }
    }
    
    mp[7] = {'p', 'q', 'r', 's'};
    mp[8] = {'t', 'u', 'v'};
    mp[9] = {'w', 'x', 'y', 'z'};
    
    vector<string> ans;
    int n = digits.size();
    
    if(n == 0){
        return {};
    }
    
    rec(0, "", mp, ans, digits, n);
    return ans;
}