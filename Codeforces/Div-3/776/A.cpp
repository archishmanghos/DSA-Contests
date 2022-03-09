void solve() {
    string S;
    char C;
    cin >> S >> C;
    int N = S.size();
    for (int i = 0; i < N; i++) {
        if (S[i] == C) {
            if (i % 2 == 0 and (N - i - 1) % 2 == 0) {
                cout << "YES" << '\n';
                return;
            }
        }
    }

    cout << "NO" << '\n';
}