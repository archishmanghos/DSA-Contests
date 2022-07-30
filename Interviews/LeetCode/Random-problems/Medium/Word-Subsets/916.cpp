vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    int cnt1[26] = {0};
    for (string s : words2) {
        int temp[26] = {0};
        for (char c : s) {
            temp[c - 'a'] += 1;
        }
        for (int i = 0; i < 26; i++) {
            cnt1[i] = max(cnt1[i], temp[i]);
        }
    }

    vector<string> ans;
    for (string s : words1) {
        int cnt2[26] = {0};
        for (char c : s) {
            cnt2[c - 'a'] += 1;
        }
        bool subset = true;
        for (int i = 0; i < 26; i++) {
            if (cnt2[i] < cnt1[i]) {
                subset = false;
                break;
            }
        }

        if (subset) ans.push_back(s);
    }

    return ans;
}