vector<int> findAnagrams(string s, string p) {
    vector<int> cnt1(26, 0), cnt2(26, 0);
    for (char c: p) {
        cnt1[c - 'a'] += 1;
    }

    vector<int> ans;
    if (p.size() > s.size()) {
        return ans;
    }

    for (int i = 0; i < p.size(); i++) {
        cnt2[s[i] - 'a'] += 1;
    }

    int i = p.size() - 1;
    while (i < s.size()) {
        int start = i - ((int) p.size() - 1);
        bool allSame = true;
        for (int j = 0; j < 26; j++) {
            allSame &= cnt1[j] == cnt2[j];
        }
        if (allSame) {
            ans.push_back(start);
        }

        i += 1;
        cnt2[s[start] - 'a'] -= 1;
        if (i < s.size()) {
            cnt2[s[i] - 'a'] += 1;
        }
    }

    return ans;
}