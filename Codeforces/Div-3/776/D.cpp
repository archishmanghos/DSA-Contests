void solve() {
    int N;
    cin >> N;
    vector<int> A;
    for (int i = 1; i <= N; i++) {
        int X;
        cin >> X;
        A.push_back(X);
    }

    int i = N - 1;
    vector<int> ans(N + 2);
    while (i >= 0) {
        if (A[i] == i + 1) {
            ans[i + 1] = 0;
        } else {
            int pos = 0;
            vector<int> back, front;
            for (int j = 0; j < i; j++) {
                back.push_back(A[j]);
                if (A[j] == i + 1) {
                    pos = j;
                    break;
                }
            }
            ans[i + 1] = pos + 1;
            for (int j = pos + 1; j <= i; j++) {
                front.push_back(A[j]);
            }
            for (int j = i + 1; j < N; j++) {
                back.push_back(A[j]);
            }

            A.clear();
            for (int j: front) {
                A.push_back(j);
            }
            for (int j: back) {
                A.push_back(j);
            }
        }
        i -= 1;
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}