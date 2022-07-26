int goodnessScore(string s) {
    vector<int> goodNess(26, 0);
    for (char c : s) {
        if (c >= 'a' and c <= 'z') goodNess[c - 'a'] -= 1;
        else goodNess[c - 'A'] += 1;
    }

    int ans = 0;
    for (int i = 0; i < 26; i++) {
        if (goodNess[i] > 0) ans += 1;
        else if (goodNess[i] < 0) ans -= 1;
    }
    return ans;
}
