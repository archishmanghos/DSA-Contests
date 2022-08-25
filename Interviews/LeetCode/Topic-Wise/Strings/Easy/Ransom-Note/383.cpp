bool canConstruct(string ransomNote, string magazine) {
    vector<int> cnt(26, 0);
    for (char c : magazine) cnt[c - 'a'] += 1;
    for (char c : ransomNote) cnt[c - 'a'] -= 1;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] < 0) return false;
    }

    return true;
}