int minLength(string s, int n) {
    stack<char> st;
    for (int i = 0; i < n; i++) {
        if (st.empty()) {
            st.push(s[i]);
        } else {
            if ((st.top() - '0') % 2 and ((st.top() - '0') + 1) % 10 == (s[i] - '0')) {
                st.pop();
            } else if ((st.top() - '0') % 2 == 0 and ((st.top() - '0') - 1 + 10) % 10 == (s[i] - '0')) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
    }

    return st.size();
}