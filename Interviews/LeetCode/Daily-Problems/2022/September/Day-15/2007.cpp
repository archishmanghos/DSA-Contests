vector<int> findOriginalArray(vector<int>& changed) {
    int n = changed.size();
    if (n & 1) return {};
    map<int, int> mp;
    for (int i : changed) mp[i] += 1;
    vector<int> ans;
    sort(changed.begin(), changed.end());

    for (int i = n - 1; i >= 0; i--) {
        if (changed[i] % 2 == 0 and mp[changed[i]] > 0) {
            if (changed[i] == 0) {
                if (mp[0] > 1) {
                    mp[0] -= 2;
                    ans.push_back(0);
                }
                continue;
            }
            if (mp.find(changed[i] / 2) != mp.end() and mp[changed[i] / 2] > 0) {
                mp[changed[i] / 2] -= 1;
                mp[changed[i]] -= 1;
                ans.push_back(changed[i] / 2);
            }
        }
    }

    if (ans.size() == n / 2) return ans;
    return {};
}