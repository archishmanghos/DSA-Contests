int stringtointeger(string x)
{
    int ans = 0, j = 1;

    for (int i = x.size() - 1; i >= 0; i--)
    {
        ans += (x[i] - '0') * j;
        j *= 10;
    }

    return ans;
}
string decodeString(string s)
{
    int n = s.size(), i = 0;
    stack<string> st;
    while(i < n)
    {
        if(s[i] == ']')
        {
            string repl = "", temp = "";
            stack<string> stt = st;
            while(st.top()[0] != '[')
            {
                repl += st.top();
                st.pop();
            }
            st.pop();
            while(!st.empty() && st.top()[0] >= '0' && st.top()[0] <= '9')
            {
                temp += st.top();
                st.pop();
            }
            reverse(temp.begin(), temp.end());
            int mul = stringtointeger(temp);
            string pushh = "";
            for(int j = 1; j <= mul; j++)
                pushh += repl;
            st.push(pushh);
        }
        else
        {
            string temp = "", ans = "";
            temp += s[i];
            st.push(temp);
            stack<string> stt = st;
        }
        i += 1;
    }
    string ans = "";
    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}