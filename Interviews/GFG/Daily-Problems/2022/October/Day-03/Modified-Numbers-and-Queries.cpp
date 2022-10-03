int sum(int x) {
    if (x == 1) return 1;
    int ans = 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            ans += i;
            while (i > 1 and x % i == 0) {
                x /= i;
            }
        }
    }

    if (x > 1) ans += x;
    return ans;
}
int sumOfAll(int l, int r) {
    int ans = 0;
    for (int i = l; i <= r; i++) {
        ans += sum(i);
    }

    return ans;
}