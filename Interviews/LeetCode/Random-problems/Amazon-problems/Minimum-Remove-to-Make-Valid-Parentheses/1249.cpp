string minRemoveToMakeValid(string s){
    string ans = "";
    stack<int> st;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' or s[i] == ')'){
            if(s[i] == '('){
                st.push(i);
            }else{
                if(st.size()){
                    st.pop();
                }else{
                    s[i] = '.';
                }
            }
        }
    }
    while(!st.empty()){
        s[st.top()] = '.';
        st.pop();
    }
    
    for(char c : s){
        if(c != '.'){
            ans += c;
        }
    }
    return ans;
}