string remove(string s){
    s += '0';
    int n = s.size();
    string newS = "";
    bool atleastOneChange = false;
    
    for(int i = 0; i < n - 1; i++){
        if(s[i] == s[i + 1]){
            while(s[i] == s[i + 1]){
                i += 1;
            }
            atleastOneChange = true;
        }else{
            newS += s[i];
        }
    }
    
    return (atleastOneChange ? remove(newS) : newS);
}