long cache[10002][7][7], mod = 1e9 + 7;
long dp(int index, int preRoll, int preToPreRoll, int &n){
	if(index == n) return 1;
	if(cache[index][preRoll][preToPreRoll] != -1) return cache[index][preRoll][preToPreRoll];

	long ans = 0;
	for(int i = 1; i <= 6; i++){
		if(i != preRoll and i != preToPreRoll){
			if(preRoll == 0 or __gcd(preRoll, i) == 1){
				ans = ((ans % mod) + (dp(index + 1, i, preRoll, n) % mod)) % mod;
			}
		}
	}

	return cache[index][preRoll][preToPreRoll] = ans;
}
int distinctSequences(int n) {
	memset(cache, -1, sizeof(cache));
    return dp(0, 0, 0, n);
}