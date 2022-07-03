int peopleAwareOfSecret(int n, int delay, int forget) {
    int cache[n + 2], mod = 1e9 + 7, newPeopleKnowing = 0, ans = 0;
    memset(cache, 0, sizeof(cache));
    cache[1] = 1;
    for(int i = delay + 1; i <= n; i++){
    	int newPeopleForgetting = cache[max(i - forget, 0)];
    	int peopleKnowing = cache[max(i - delay, 0)];
    	cache[i] = newPeopleKnowing = ((newPeopleKnowing % mod) + ((peopleKnowing - newPeopleForgetting + mod)) % mod) % mod;
    }

    for(int i = n - forget + 1; i <= n; i++) ans = (ans + cache[i]) % mod;
    return ans;
}