bool checkPal(string s){
    int i = 0, j = s.size() - 1;
    while(i < j){
        if(s[i] != s[j]){
            return false;
        }
        i += 1;
        j -= 1;
    }
    return true;
}
bool validPalindrome(string s){
    int i = 0, j = s.size() - 1;
    int pos1 = -1, pos2 = -1;
    while(i < j){
        if(s[i] != s[j]){
            pos1 = i;
            pos2 = j;
            break;
        }
        i += 1;
        j -= 1;
    }
    
    if(pos1 == -1){
        return true;
    }
    
    string s1 = "", s2 = "";
    for(int i = 0; i < s.size(); i++){
        if(i != pos1){
            s1 += s[i];
        }
        if(i != pos2){
            s2 += s[i];
        }
    }
    
    return (checkPal(s1) or checkPal(s2));
}