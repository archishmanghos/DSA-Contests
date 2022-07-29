string normaliseString(string s) {
    int n = s.size(), cnt = 0;
    vector<int> mapped(26, -1);
    for (int i = 0; i < n; i++) {
        if (mapped[s[i] - 'a'] == -1) {
            mapped[s[i] - 'a'] = cnt;
            cnt += 1;
        }
        s[i] = (mapped[s[i] - 'a'] + 'a');
    }
    return s;
}
vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> ans;
    pattern = normaliseString(pattern);

    for (string s : words) {
        if (normaliseString(s) == pattern) {
            ans.push_back(s);
        }
    }

    return ans;
}