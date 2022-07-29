string normaliseString(string s) {
    int n = s.size(), cnt = 0;
    map<char, char> mapped;
    for (int i = 0; i < n; i++) {
        if (mapped.find(s[i]) == mapped.end()) {
            mapped[s[i]] = (cnt + 'a');
            cnt += 1;
        }
        s[i] = mapped[s[i]];
    }
    return s;
}
bool isIsomorphic(string s, string t) {
    return normaliseString(s) == normaliseString(t);
}