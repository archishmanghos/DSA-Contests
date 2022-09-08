int longestZSubstring(int k, string s) {
    int i = 0, j = 0, ans = 0, cnt = 0;
    while (j < s.size()) {
        if (s[j] != 'Z') cnt += 1;
        while (cnt > k) {
            if (s[i] != 'Z') cnt--;
            i++;
        }
        ans = max(ans, j - i + 1);
        j++;
    }
    return ans;
}