string simplifyPath(string path){
    stack<char> st;
    for(int i = 0; i < path.size(); i++){
        if(st.size() == 0){
            st.push(path[i]);
        }else{
            if(path[i] == '/' and st.top() == '/'){
                continue;
            }else if(path[i] == '/' and st.top() == '.'){
                char c = st.top();
                st.pop();
                if(st.top() != '/'){
                    st.push(c);
                    st.push(path[i]);
                    continue;
                }
            }else if(path[i] == '.' and st.top() == '/' and (i + 1 >= path.size() or path[i + 1] == '/')){
                continue;
            }else if(path[i] == '.' and st.top() == '.' and (i + 1 >= path.size() or path[i + 1] == '/')){
                char c = st.top();
                st.pop();
                if(st.top() != '/'){
                    st.push(c);
                    st.push(path[i]);
                    continue;
                }else{
                    st.push(c);
                }
                int slash = 0;
                stack<char> temp = st;
                bool ok = false;
                while(!temp.empty()){
                    slash += temp.top() == '/';
                    temp.pop();
                    if(slash > 1){
                        ok = true;
                        break;
                    }
                }
                if(ok){
                    slash = 0;
                    while(!st.empty()){
                        slash += st.top() == '/';
                        if(slash == 2){
                            break;
                        }
                        st.pop();
                    }
                }else{
                    st.pop();
                }
            }else{
                st.push(path[i]);
            }
        }
    }
    if(st.size() > 1 and st.top() == '/'){
        st.pop();
    }
    
    string ans = "";
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}