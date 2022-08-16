int firstUniqChar(string s) {
    vector<int> ind(26, -2);
    for (int i = 0; i < s.size(); i++) {
        if (ind[s[i] - 'a'] == -2) ind[s[i] - 'a'] = i;
        else ind[s[i] - 'a'] = -1;
    }

    int ans = -1;
    for (int i = 0; i < 26; i++) {
        if (ind[i] >= 0) {
            if (ans == -1) ans = ind[i];
            else ans = min(ans, ind[i]);
        }
    }

    return ans;
}