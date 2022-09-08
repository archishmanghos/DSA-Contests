vector<int> smallestArray(int n, int m, vector<int> &a, vector<int> &l, vector<int> &r) {
    vector<pair<int, int>> v;
    for (int i = 0; i < m; i++) {
        v.push_back({l[i], r[i]});
    }

    sort(v.begin(), v.end());

}
