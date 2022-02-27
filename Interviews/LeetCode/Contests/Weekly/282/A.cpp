int prefixCount(vector <string> &words, string pref) {
    int ans = 0, sz = pref.size();
    for (string s: words) {
        if (sz <= s.size()) {
            ans += (s.substr(0, sz) == pref);
        }
    }

    return ans;
}