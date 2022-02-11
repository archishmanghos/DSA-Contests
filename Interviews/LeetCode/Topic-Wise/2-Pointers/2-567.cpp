bool checkInclusion(string s1, string s2) {
    int N1 = s1.size(), N2 = s2.size();
    vector<int> cnt(26, 0);
    for (char c: s1) {
        cnt[c - 'a'] += 1;
    }

    if (N2 < N1) {
        return false;
    }

    vector<int> cntTemp(26, 0);
    for (int i = 0; i < N1; i++) {
        cntTemp[s2[i] - 'a'] += 1;
    }
    int i = -1, j = N1 - 1;
    while (j < N2) {
        for (int k = 0; k < 26; k++) {
            bool allSame = true;
            for (int k = 0; k < 26; k++) {
                allSame &= cntTemp[k] == cnt[k];
            }
            if (allSame) {
                return true;
            }

            i += 1;
            j += 1;
            if (j == N2) {
                break;
            }
            cntTemp[s2[i] - 'a'] -= 1;
            cntTemp[s2[j] - 'a'] += 1;
        }
    }

    return false;
}