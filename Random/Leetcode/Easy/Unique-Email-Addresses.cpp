string convertToActualEmail(string s)
{
    int pos;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '@')
        {
            pos = i;
            break;
        }
    }
    string firstPart = s.substr(0, pos);
    string ans = "";
    for(int i = 0; i < firstPart.size(); i++)
    {
        if(firstPart[i] == '.')
            continue;
        if(firstPart[i] == '+')
            break;
        ans += firstPart[i];
    }
    for(int i = pos; i < s.size(); i++)
        ans += s[i];
    return ans;
}
int numUniqueEmails(vector<string> &emails)
{
    set<string> ans;
    for(int i = 0; i < emails.size(); i++)
    {
        string goodEmail = convertToActualEmail(emails[i]);
        ans.insert(goodEmail);
    }
    int x = (int)ans.size();
    return x;
}

/*

Time-Complexity: O(emails.size()*emails[i].size())
Space-Complexity: O(emails.size()*emails[i].size())

Easy implementation problem
*/
