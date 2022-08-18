int minSetSize(vector<int>& arr) {
    vector<int> cnt(100100, 0);
    for (int i : arr) {
        cnt[i] += 1;
    }

    sort(cnt.begin(), cnt.end());
    reverse(cnt.begin(), cnt.end());
    int ans = 0, sz = arr.size();
    for (int i = 0; ; i++) {
        if (!cnt[i]) break;
        sz -= cnt[i];
        ans += 1;
        if (sz * 2 <= arr.size()) break;
    }

    return ans;
}