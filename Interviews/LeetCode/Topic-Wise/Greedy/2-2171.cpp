long long minimumRemoval(vector<int> &beans) {
    sort(beans.begin(), beans.end());
    long long ans = 0, total;
    for (int i = 0; i < beans.size(); i++) {
        ans += beans[i];
    }
    total = ans;

    for (int i = 0; i < beans.size(); i++) {
        long long left = beans.size() - i - 1;
        if (left > 0) {
            ans = min(ans, total - (long long) (left * beans[i + 1]));
        } else {
            ans = min(ans, total);
        }

        ans = min(ans, total - (long long) ((left + 1) * beans[i]));
    }

    return ans;
}