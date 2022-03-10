void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N + 2);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    int MOD = 1e9 + 7;
    for (int i = 1; i <= M; i++) {
        int C1, X1, C2, X2;
        cin >> C1 >> X1;
        for (int j = 1; j <= X1; j++) {
            cin >> X2 >> C2;
            A[C2] = ((A[C2] % MOD) + ((A[C1] % MOD) * (X2 % MOD))) % MOD;
        }
        A[C1] = 0;
    }

    for (int i = 1; i <= N; i++) {
        cout << A[i] << '\n';
    }

    return 0;
}