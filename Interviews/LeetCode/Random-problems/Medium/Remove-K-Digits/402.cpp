string removeKdigits(string num, int k) {
    stack<char> st;
    for (int i = 0; i < num.size(); i++) {
        while (!st.empty() and k > 0 and num[i] < st.top()) {
            st.pop();
            k -= 1;
        }
        st.push(num[i]);
    }
    string ans = "";
    while (!st.empty()) {
        if (!k) {
            ans += st.top();
        } else {
            k -= 1;
        }
        st.pop();
    }

    if (!ans.size()) {
        return "0";
    }

    reverse(ans.begin(), ans.end());
    int pos = 0;
    for (int i = 0; i < ans.size() - 1; i++) {
        if (ans[i] == '0') {
            pos = i + 1;
        } else {
            break;
        }
    }

    return ans.substr(pos);
}