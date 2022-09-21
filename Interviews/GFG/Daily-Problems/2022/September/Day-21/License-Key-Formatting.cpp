string ReFormatString(string S, int K) {
    int n = 0;
    for (char c : S) {
        n += c != '-';
    }

    int firstPart = n % K, j = 0, start = 0;
    string ans = "";
    for (int i = 0; i < S.size(); i++) {
        if (j == firstPart) {
            start = i, j = 0;
            break;
        }

        if (S[i] != '-') {
            j += 1;
            if (S[i] >= 'a' and S[i] <= 'z') {
                ans += ((S[i] - 'a') + 'A');
            } else {
                ans += S[i];
            }
        }
    }

    if (j != 0) return ans;
    if (firstPart > 0) ans += '-';

    for (int i = start; i < S.size(); i++) {
        if (j == K) {
            ans += '-';
            j = 0;
        }

        if (S[i] != '-') {
            j += 1;
            if (S[i] >= 'a' and S[i] <= 'z') {
                ans += ((S[i] - 'a') + 'A');
            } else {
                ans += S[i];
            }
        }
    }

    if (ans.back() == '-') ans.pop_back();
    return ans;
}