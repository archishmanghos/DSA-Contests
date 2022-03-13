bool isValid(string s){
    if((int)s.size() % 2){
        return false;
    }
    
    stack<char> st;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' or s[i] == '{' or s[i] == '['){
            st.push(s[i]);
        }else{
            if(st.size() and ((s[i] == ')' and st.top() == '(') or (s[i] == '}' and st.top() == '{') or (s[i] == ']' and st.top() == '['))){
                st.pop();
            }else{
                return false;
            }
        }
    }
    
    return st.size() == 0;
}