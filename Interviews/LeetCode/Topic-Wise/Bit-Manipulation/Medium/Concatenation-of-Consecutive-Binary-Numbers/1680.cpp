int toAdd(int x, long &power, int mod = 1e9 + 7) {
    long ans = 0;
    int len = 0, x1 = x;
    while (x1 > 0) {
        len += 1;
        x1 >>= 1;
    }

    for (int i = 0; i < len; i++) {
        if ((x >> i) & 1) {
            ans = (ans % mod + power % mod) % mod;
        }
        power = ((power % mod) * 2) % mod;
    }

    return ans % mod;
}
int concatenatedBinary(int n) {
    long power = 1, ans = 0, mod = 1e9 + 7;
    for (int i = n; i >= 1; i--) {
        ans = (ans % mod + toAdd(i, power)) % mod;
    }

    return int(ans);
}