int ninjaAndAuction(vector<int>&a, vector<int>&b) {
    vector<int> v1, v2;
    int n = a.size();

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) v[i] = {a[i], b[i]};
    sort(v.begin(), v.end());

    v1.push_back(v[0].first), v2.push_back(v[0].second);
    for (int i = 1; i < n; i++) {
        if (a[i] > v1.back() and b[i] > v2.back()) {
            v1.push_back(v[i].first), v2.push_back(v[i].second);
        } else {
            int index1 = lower_bound(v1.begin(), v1.end(), v[i].first) - v1.begin();
            int index2 = lower_bound(v2.begin(), v2.end(), v[i].second) - v2.begin();
            if (index1 == index2) {
                v1[index1] = v[i].first, v2[index2] = v[i].second;
            }
        }
    }

    return v1.size();
}
