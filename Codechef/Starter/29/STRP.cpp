void solve() {
    int N;
    string S;
    cin >> N >> S;
    int cnt = 0, ans = 0;
    char pre = 'A';

    for (int i = 0; i < N; i++) {
        if (S[i] != pre) {
            ans += (cnt + 1) / 2;
            cnt = 1;
            pre = S[i];
        } else {
            cnt += 1;
        }
    }
    ans += (cnt + 1) / 2;
    cout << ans << '\n';
}