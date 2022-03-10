void solve() {
    int N, A;
    cin >> N;
    vector<int> add, subtract;
    for (int i = 1; i <= N; i++) {
        cin >> A;
        if (i & 1) {
            add.push_back(abs(A));
        } else {
            subtract.push_back(abs(A));
        }
    }

    sort(add.begin(), add.end());
    sort(subtract.begin(), subtract.end(), greater<int>());

    int ans = 0;
    if (subtract[0] > add[0]) {
        ans += (subtract[0] - add[0]);
        for (int i = 1; i < add.size(); i++) {
            ans += add[i];
        }
        for (int i = 1; i < subtract.size(); i++) {
            ans -= subtract[i];
        }
    } else {
        for (int i = 0; i < add.size(); i++) {
            ans += add[i];
        }
        for (int i = 0; i < subtract.size(); i++) {
            ans -= subtract[i];
        }
    }

    cout << ans << '\n';
}