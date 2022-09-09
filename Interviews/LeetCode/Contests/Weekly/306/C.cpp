void dp(int index, int n, string s, int mask, string &ans, string &pattern) {
    if (index > n) {
        ans = min(ans, s);
        return;
    }

    int start = 1, end = 9;
    if (index > 0) {
        if (pattern[index - 1] == 'I') start = (s.back() - '0') + 1;
        else end = (s.back() - '0') - 1;
    }

    for (int i = start; i <= end; i++) {
        if (!((mask >> i) & 1)) {
            mask |= (1 << i);
            s += (i + '0');
            dp(index + 1, n, s, mask, ans, pattern);
            s.pop_back();
            mask ^= (1 << i);
        }
    }
}
string smallestNumber(string pattern) {
    int n = pattern.size();
    string ans = string(n + 1, '9');
    dp(0, n, "", 0, ans, pattern);
    return ans;
}