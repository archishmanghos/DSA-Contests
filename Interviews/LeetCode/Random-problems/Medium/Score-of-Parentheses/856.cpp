int scoreOfParentheses(string s){
    stack<int> st;
    st.push(0);
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            st.push(0);
        }else{
            int x = st.top();
            x = max(1, x * 2);
            st.pop();
            int y = st.top();
            st.pop();
            st.push(x + y);
        }
    }
    return st.top();
}