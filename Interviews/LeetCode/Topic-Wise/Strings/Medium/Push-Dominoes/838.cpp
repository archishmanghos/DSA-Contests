string pushDominoes(string dominoes) {
    int n = dominoes.size(), startPos = 0, start = (dominoes[0] == 'L' ? -1 : dominoes[0] == '.' ? 0 : 1); // L = -1, . = 0, R = 1
    vector<vector<int>> positions;
    for (int i = 1; i < n; i++) {
        if (dominoes[i] == 'L') {
            positions.push_back({startPos, i, start, -1});
            start = -1, startPos = i;
        } else if (dominoes[i] == 'R') {
            positions.push_back({startPos, i, start, 1});
            start = 1, startPos = i;
        }
    }

    if (dominoes.back() == '.') {
        positions.push_back({startPos, n - 1, start, 0});
    }

    string ans = dominoes;
    for (auto i : positions) {
        int spos = i[0], epos = i[1], s = i[2], e = i[3];
        if (s == 0) {
            if (e == -1) {
                for (int j = spos; j < epos; j++) {
                    ans[j] = 'L';
                }
            }
        } else if (s == -1) {
            if (e == -1) {
                for (int j = spos + 1; j < epos; j++) {
                    ans[j] = 'L';
                }
            }
        } else {
            if (e == 0 or e == 1) {
                for (int j = spos + 1; j <= epos; j++) {
                    ans[j] = 'R';
                }
            } else {
                int spread = (epos - spos - 1) / 2;
                for (int j = spos + 1; j <= spos + spread; j++) {
                    ans[j] = 'R';
                }
                for (int j = epos - 1; j >= epos - spread; j--) {
                    ans[j] = 'L';
                }
            }
        }
    }

    return ans;
}