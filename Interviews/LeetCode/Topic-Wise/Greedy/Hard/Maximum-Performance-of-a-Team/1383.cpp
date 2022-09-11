int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = {speed[i], efficiency[i]};
    }

    sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    });

    priority_queue<int, vector<int>, greater<int>> pq;
    int64_t sumSpeed = 0, ans = 0, mod = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        sumSpeed += v[i].first;
        pq.push(v[i].first);
        if (pq.size() > k) {
            sumSpeed -= pq.top();
            pq.pop();
        }

        ans = max(ans, sumSpeed * v[i].second);
    }

    return int(ans % mod);
}