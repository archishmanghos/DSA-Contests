void rec(int index, string s, string &digits, map<char, string> &mp, vector<string> &ans)
{
    if(index == digits.size())
    {
        if(s.size())
            ans.push_back(s);
        return;
    }

    for(int i = 0; i < mp[digits[index]].size(); i++)
    {
        string temp = s + mp[digits[index]][i];
        rec(index + 1, temp, digits, mp, ans);
    }

}
vector<string> letterCombinations(string digits)
{
    map<char, string> mp;
    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";
    vector<string> ans;
    rec(0, "", digits, mp, ans);
    return ans;
}