string previousNumber(string S){
    stack<int> st;
    int n = S.size(), pos1 = -1, pos2 = -1;
    for(int i = n - 1; i >= 0; i--){
        if(st.empty() or S[i] <= S[i + 1]){
            st.push(i);
        }else{
            pos1 = i, pos2 = i;
            while(!st.empty()){
                if(S[st.top()] < S[pos1]){
                    if(S[st.top()] != S[pos2]){
                        pos2 = st.top();
                    }
                }
                st.pop();
            }
            break;
        }
    }
    
    if(pos1 == -1){
        return "-1";
    }
    
    swap(S[pos1], S[pos2]);
    if(S[0] == '0'){
        return "-1";
    }
    
    return S;
}