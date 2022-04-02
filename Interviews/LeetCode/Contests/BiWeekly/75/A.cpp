string addPaddingOfZeroes(string x, int length){
    int n = x.size();
    if(n == length){
        return x;
    }

    for(int i = 1; i <= (length - n); i++){
        x = '0' + x;
    }

    return x;
}
string integertobinary(int x){
    string ans = "";
    while(x > 0){
        ans += (x % 2) + '0';
        x >>= 1;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int minBitFlips(int start, int goal){
    string s1 = integertobinary(start);
    string s2 = integertobinary(goal);
    
    int n = max((int)s1.size(), (int)s2.size());
    s1 = addPaddingOfZeroes(s1, n);
    s2 = addPaddingOfZeroes(s2, n);
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += s1[i] != s2[i];
    }
    
    return ans;
}