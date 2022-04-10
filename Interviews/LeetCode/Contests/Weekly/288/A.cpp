string integertostring(int x){
    string ans = "";
    while (x > 0){
        ans += (x % 10) + '0';
        x /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
long stringtointeger(string x){
    long ans = 0, j = 1;
    for (int i = x.size() - 1; i >= 0; i--){
        ans += (x[i] - '0') * j;
        j *= 10;
    }

    return ans;
}
int largestInteger(int num){
    string s = integertostring(num);
    for(int i = 0; i < s.size(); i++){
        int ch = (s[i] - '0');
        if(ch % 2 == 0){
            int posEven = -1;
            char maxEven = s[i];
            for(int j = s.size() - 1; j > i; j--){
                if((s[j] - '0') % 2 == 0){
                    if(s[j] > maxEven){
                        maxEven = s[j];
                        posEven = j;
                    }
                }
            }
            if(posEven != -1){
                swap(s[i], s[posEven]);
            }
        }else{
            int posOdd = -1;
            char maxOdd = s[i];
            for(int j = s.size() - 1; j > i; j--){
                if((s[j] - '0') % 2 == 1){
                    if(s[j] > maxOdd){
                        maxOdd = s[j];
                        posOdd = j;
                    }
                }
            }
            if(posOdd != -1){
                swap(s[i], s[posOdd]);
            }
        }
    }
    
    return stringtointeger(s);
}