int numberOfWeakCharacters(vector<vector<int>>& properties) {
    sort(properties.begin(), properties.end(), [](const vector<int> &a, const vector<int> &b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });

    int ans = 0, maxx = INT_MIN;
    for (int i = properties.size() - 1; i >= 0; i--) {
        if (properties[i][1] < maxx) {
            ans += 1;
        }
        maxx = max(maxx, properties[i][1]);
    }

    return ans;
}