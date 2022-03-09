void solve() {
    int N, M;
    cin >> N >> M;
    vector<pair<pair<int, int>, int>> A(M + 2);
    for (int i = 1; i <= M; i++) {
        cin >> A[i].first.first >> A[i].first.second;
        A[i].second = i;
    }

    auto cmp = [](pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b) {
        return a.first.second < b.first.second;
    };

    sort(A.begin() + 1, A.begin() + M + 1, cmp);
    vector<pair<int, int>> finalPoints;
    for (int i = 1; i <= 2 * N; i++) {
        finalPoints.push_back({A[i].first.first, A[i].second});
    }
    sort(finalPoints.begin(), finalPoints.end());
    int ans = 0;
    for (int i = 1; i <= 2 * N; i++) {
        ans += A[i].first.second;
    }

    cout << ans << '\n';
    auto it1 = finalPoints.begin(), it2 = finalPoints.end();
    it2--;
    while (it1 < it2) {
        cout << (*it1).second << ' ' << (*it2).second << '\n';
        it1++;
        it2--;
    }
}