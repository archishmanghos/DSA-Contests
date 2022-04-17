string integertostring(int x){
    if(x == 0){
        return "0";
    }
    
    string ans = "";
    while (x > 0){
        ans += (x % 10) + '0';
        x /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string digitSum(string s, int k){
    while((int)s.size() > k){
        string t = "", temp = "";
        for(int i = 0; i < s.size(); i++){
            if(temp.size() < k){
                temp += s[i];
            }else{
                int newS = 0;
                for(char c : temp){
                    newS += (c - '0');
                }
                t += integertostring(newS);
                temp = s[i];
            }
        }

        int newS = 0;
        for(char c : temp){
            newS += (c - '0');
        }
        t += integertostring(newS);
        s = t;
    }

    return s;
}