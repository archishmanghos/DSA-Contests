int minimumTime(string s) {
    int left = 0, ans = (int) s.size() * 2;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            left = min(left + 2, i + 1);
        }
        ans = min(ans, left + ((int) s.size() - 1 - i));
    }
    return ans;
}