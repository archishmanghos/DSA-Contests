long long numberOfWays(string s){
    long long cnt[2] = {0LL};
    long long ans = 0;
    for(char c : s){
        cnt[c - '0'] += 1;
    }
    
    long long z = 0, o = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0'){
            ans += o * (cnt[1] - o);
            z += 1;
        }else{
            ans += z * (cnt[0] - z);
            o += 1;
        }
    }
    
    return ans;
}