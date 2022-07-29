int tileCleaning(int n, int k) {
    int ans1 = (n - k) * 2 + (k - 1);
    int ans2 = (k - 1) * 2 + (n - k);
    return min(ans1, ans2);
}