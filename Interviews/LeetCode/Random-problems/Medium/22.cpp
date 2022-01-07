void rec(vector<string> &ans, int &n, string s)
{
    int opening = 0, closing = 0;
    for(char c : s)
    {
        opening += c == '(';
        closing += c == ')';
    }

    opening = n - opening;
    closing = n - closing;
    if(opening == 0 and closing == 0)
    {
        ans.push_back(s);
        return;
    }

    string temp = s;
    if(opening == 0)
    {
        temp += ')';
        rec(ans, n, temp);
    }
    else if(closing > opening)
    {
        temp += '(';
        rec(ans, n, temp);
        temp = s;
        temp += ')';
        rec(ans, n, temp);
    }
    else
    {
        temp += '(';
        rec(ans, n, temp);
    }
}
vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    rec(ans, n, "");
    return ans;
}