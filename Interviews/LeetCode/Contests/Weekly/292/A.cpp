int stringToInteger(string s){
    int ans = 0, j = 1;
    for(int i = s.size() - 1; i >= 0; i--){
        ans += (s[i] - '0') * j;
        j *= 10;
    }
    
    return ans;
}
string largestGoodInteger(string num){
    string ans = "";
    int largest = -1;
    for(int i = 0; i < num.size() - 2; i++){
        string temp = "";
        int j = i;
        while(temp.size() < 3 and num[j] == num[i]){
            temp += num[j++];
        }
        
        if(temp.size() == 3){
            int nowInt = stringToInteger(temp);
            if(nowInt > largest){
                ans = temp;
                largest = nowInt;
            }
        }
    }
    
    return ans;
}