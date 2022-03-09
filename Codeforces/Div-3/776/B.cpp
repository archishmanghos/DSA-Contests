void solve() {
    int L, R, A;
    cin >> L >> R >> A;

    int term1 = (L / A);
    int term2 = (R / A);
    if (term1 != term2) {
        int ans1 = (term2 * A - 1) / A + (term2 * A - 1) % A;
        int ans2 = (R / A) + (R % A);
        cout << max(ans1, ans2) << '\n';
    } else {
        int ans = (R / A) + (R % A);
        cout << ans << '\n';
    }
}