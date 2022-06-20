int longestSubsequence(string s, int k) {
    long long n = s.size(), ans = 0;
    for(long long i = n - 1; i >= 0; i--){
        long long numTillNow = 0, countBits = 0, lengthNow = i;
        if(lengthNow + 1 <= ans) break;
        for(long long j = i; j >= 0; j--){
            if(s[j] == '1'){
                if(lengthNow - j <= 35){
                    long long canBeNum = numTillNow | (1LL << (lengthNow - j));
                    if(canBeNum <= k * 1LL) numTillNow = canBeNum, countBits += 1;
                }
            }else countBits += 1;
        }

        ans = max(ans, countBits);
    }

    return ans;
}