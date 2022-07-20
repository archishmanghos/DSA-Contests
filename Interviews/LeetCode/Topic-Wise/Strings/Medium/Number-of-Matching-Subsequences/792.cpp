bool checkSubSequence(string t, vector<vector<int>> &indices) {
    int j = -1;
    for (int i = 0; i < t.size(); i++) {
        int now = t[i] - 'a';
        if (indices[now].size() == 0) return false;
        if (indices[now].back() <= j) return false;
        int indexOfNearestCharInS = upper_bound(indices[now].begin(), indices[now].end(), j) - indices[now].begin();
        j = indices[now][indexOfNearestCharInS];
    }

    return true;
}

int numMatchingSubseq(string s, vector<string>& words) {
    vector<vector<int>> indices(26);
    for (int i = 0; i < s.size(); i++) {
        indices[s[i] - 'a'].push_back(i);
    }

    int ans = 0;
    for (int i = 0; i < words.size(); i++) {
        ans += checkSubSequence(words[i], indices);
    }

    return ans;
}