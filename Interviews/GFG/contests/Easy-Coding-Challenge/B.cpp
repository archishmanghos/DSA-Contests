int countSubstring(string S) {
    int n = S.size(), u = 0, l = 0;
    vector<int> lower(n, 0), upper(n, 0);
    for (int i = 0; i < n; i++) {
        if (S[i] >= 'A' and S[i] <= 'Z') u += 1;
        else l += 1;
        lower[i] = l;
        upper[i] = u;
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int lowerCase = lower[j] - (i > 0 ? lower[i - 1] : 0);
            int upperCase = upper[j] - (i > 0 ? upper[i - 1] : 0);
            ans += lowerCase == upperCase;
        }
    }

    return ans;
}