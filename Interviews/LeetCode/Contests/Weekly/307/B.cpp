string largestPalindromic(string num) {
    vector<int> cnt(10, 0);
    for (char c : num) cnt[c - '0'] += 1;
    bool ok1 = true, ok2 = true;
    for (int i = 1; i <= 9; i++) {
        ok1 &= cnt[i] == 0;
        ok2 &= cnt[i] <= 1;
    }
    if (ok1) return "0";
    if (ok2) {
        for (int i = 9; i >= 0; i--) {
            if (cnt[i] == 1) return string(1, (i + '0'));
        }
    }

    int highestOdd = -1, length = 0;
    for (int i = 0; i <= 9; i++) {
        if (cnt[i] % 2) highestOdd = i;
        cnt[i] >>= 1;
        length += cnt[i] * 2;
    }

    if (highestOdd != -1) length += 1;
    string ans = string(length, '*');
    int i = (length + 1) / 2, j;

    for (j = 0; j <= 9; j++) {
        for (int k = 1; k <= cnt[j]; k++) {
            ans[i++] = (j + '0');
        }
    }

    i = (length / 2) - 1, j = (length + 1) / 2;
    while (j < length) {
        ans[i--] = ans[j++];
    }

    if (length % 2) ans[length / 2] = (highestOdd + '0');

    return ans;
}