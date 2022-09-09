int edgeScore(vector<int>& edges) {
    int n = edges.size();
    vector<int64_t> edgeScore(n, 0);
    for (int i = 0; i < n; i++) {
        edgeScore[edges[i]] += i;
    }

    int64_t maxx = INT_MIN, ans = -1;
    for (int i = 0; i < n; i++) {
        if (edgeScore[i] > maxx) {
            maxx = edgeScore[i];
            ans = i;
        }
    }

    return int(ans);
}