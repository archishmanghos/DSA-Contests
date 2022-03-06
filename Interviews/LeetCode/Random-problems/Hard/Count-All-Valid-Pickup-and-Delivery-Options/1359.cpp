int countOrders(int n) {
    long long ans = 1, mod = 1e9 + 7;
    for (int i = 1; i <= 2 * n; i++) {
        if (i & 1) {
            ans = (ans * i) % mod;
        } else {
            ans = (ans * (i / 2)) % mod;
        }
    }

    return ans;
}