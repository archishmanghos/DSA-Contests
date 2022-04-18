long long karyTree(int k, int m){
    long long ans = 1, MOD = 1e9 + 7;
    while(m > 0){
        if(m & 1){
            ans = ((ans % MOD) * k) % MOD;
        }
        k = ((k % MOD) * (k % MOD)) % MOD;
        m >>= 1;
    }
    return ans;
}