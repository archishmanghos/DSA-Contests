string repeatLimitedString(string s, int repeatLimit) {
    string ans = "";
    vector<int> cnt(30, 0);
    for (char c: s) {
        cnt[c - 'a'] += 1;
    }

    for (char c = 'z'; c >= 'a'; c--) {
        if (cnt[c - 'a']) {
            int repeat = (cnt[c - 'a'] + repeatLimit - 1) / repeatLimit;
            if (repeat > 1) {
                string add = "";
                for (int i = 1; i <= repeatLimit; i++) {
                    add += c;
                }

                char mid = '0';
                for (char d = c - 1; d >= 'a'; d--) {
                    if (cnt[d - 'a']) {
                        mid = d;
                        break;
                    }
                }

                if (mid != '0') {
                    ans += add;
                    cnt[c - 'a'] -= repeatLimit;
                    for (int i = 2; i <= repeat - 1; i++) {
                        ans += mid;
                        cnt[mid - 'a'] -= 1;

                        ans += add;
                        cnt[c - 'a'] -= repeatLimit;

                        if (cnt[mid - 'a'] == 0) {
                            mid = '0';
                            for (char d = c - 1; d >= 'a'; d--) {
                                if (cnt[d - 'a']) {
                                    mid = d;
                                    break;
                                }
                            }
                            if (mid == '0') {
                                break;
                            }
                        }
                    }

                    if (mid != '0') {
                        ans += mid;
                        cnt[mid - 'a'] -= 1;
                        for (int i = 1; i <= cnt[c - 'a']; i++) {
                            ans += c;
                        }
                    }
                } else {
                    ans += add;
                }
            } else {
                for (int i = 1; i <= cnt[c - 'a']; i++) {
                    ans += c;
                }
            }
        }
    }
    return ans;
}