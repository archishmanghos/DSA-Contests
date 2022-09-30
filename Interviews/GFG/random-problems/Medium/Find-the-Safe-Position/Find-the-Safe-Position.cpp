int helper(int n , int k) {
    if (n == 1) return 0;
    int a = helper(n - 1 , k);
    int b = (a + k) % n;
    return b;
}

int safePos(int n, int k) {
    return 1 + helper(n, k);
}