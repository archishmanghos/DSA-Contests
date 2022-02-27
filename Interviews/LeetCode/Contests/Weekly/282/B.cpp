int minSteps(string s, string t) {
    vector<int> cnt1(30, 0), cnt2(30, 0);

    for (char c: s) {
        cnt1[c - 'a'] += 1;
    }
    for (char c: t) {
        cnt2[c - 'a'] += 1;
    }

    int ans = 0;
    for (int i = 0; i < 26; i++) {
        ans += max((int) 0, (cnt1[i] - cnt2[i]));
    }
    for (int i = 0; i < 26; i++) {
        ans += max((int) 0, (cnt2[i] - cnt1[i]));
    }

    return ans;
}