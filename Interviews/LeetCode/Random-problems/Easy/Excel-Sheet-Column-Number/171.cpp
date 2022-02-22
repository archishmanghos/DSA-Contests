int titleToNumber(string columnTitle) {
    int n = columnTitle.size();
    int ans = 1, x = 1;
    for (int i = 1; i < n; i++) {
        x *= 26;
        ans += x;
    }

    for (int i = 0; i < n; i++) {
        ans += (columnTitle[i] - 'A') * x;
        x /= 26;
    }

    return ans;
}