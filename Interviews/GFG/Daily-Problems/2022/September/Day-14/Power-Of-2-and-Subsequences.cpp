long long numberOfSubsequences(int N, long long A[]) {
    long long countPower2 = 0, ans = 1, mod = 1e9 + 7;
    for (int i = 0; i < N; i++) {
        if ((A[i] & (A[i] - 1)) == 0) {
            countPower2 += 1;
        }
    }

    for (int i = 1; i <= countPower2; i++) {
        ans = (ans * 2) % mod;
    }

    return max(0LL, ans - 1);
}