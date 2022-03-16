bool validateStackSequences(vector<int> &pushed, vector<int> &popped){
    stack<int> st;
    int j = 0;
    for(int i = 0; i < pushed.size(); i++){
        st.push(pushed[i]);
        while(st.size() and st.top() == popped[j]){
            st.pop();
            j += 1;
        }
    }
    
    if(j < popped.size()){
        while(!st.empty()){
            if(st.top() == popped[j]){
                st.pop();
                j += 1;
            }else{
                break;
            }
        }
    }
    return st.size() == 0;
}