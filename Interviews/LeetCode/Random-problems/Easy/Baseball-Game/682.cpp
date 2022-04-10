int calPoints(vector<string> &ops){
    vector<int> st;
    for(string s : ops){
        if(s == "C"){
            st.pop_back();
        }else if(s == "D"){
            st.push_back(st.back() * 2);
        }else if(s == "+"){
            st.push_back(st[st.size() - 1] + st[st.size() - 2]);
        }else{
            int newEl = 0, j = 1, n = s.size(), limit = 0;
            bool negative = false;
            if(s[0] == '-'){
                negative = true, limit = 1;
            }
            for(int i = n - 1; i >= limit; i--){
                newEl += j * (s[i] - '0');
                j *= 10;
            }
            newEl *= (negative ? -1 : 1);
            st.push_back(newEl);
        }
    }
    
    int ans = 0;
    for(int i : st){
        ans += i;
    }
    
    return ans;
}