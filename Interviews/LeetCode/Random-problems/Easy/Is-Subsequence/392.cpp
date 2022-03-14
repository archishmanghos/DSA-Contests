bool isSubsequence(string s, string t) {
    int i = 0;
    for (int j = 0; j < t.size(); j++) {
        if (s[i] == t[j]) {
            i += 1;
        }
        if (i == s.size()) {
            return true;
        }
    }

    return i == s.size();
}