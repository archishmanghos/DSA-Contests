string lexicographicallySmallest(string S, int k) {
    int n = S.size();
    if (n & (n - 1)) k <<= 1;
    else k >>= 1;

    if (k >= n) return "-1";
    string ans = "";
    for (int i = 0; i < n; i++) {
        while (k > 0 and ans.size() and ans.back() > S[i]) ans.pop_back(), k--;
        ans.push_back(S[i]);
    }

    while (k--) ans.pop_back();

    return ans;
}