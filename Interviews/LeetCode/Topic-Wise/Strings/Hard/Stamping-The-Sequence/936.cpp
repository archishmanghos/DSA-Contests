vector<int> movesToStamp(string stamp, string target) {
    int n1 = stamp.size(), n2 = target.size();
    vector<string> allComb;
    for (int i = 0; i < n1; i++) {
        for (int j = i; j < n1; j++) {
            string comp = string(i, '*') + stamp.substr(i, j - i + 1) + string(n1 - j - 1, '*');
            allComb.push_back(comp);
        }
    }

    vector<int> ans;
    while (true) {
        bool ok = false;
        for (int i = 0; i < allComb.size(); i++) {
            size_t pos = target.find(allComb[i]);
            if (pos != string::npos) {
                ok = true;
                ans.push_back(pos);
                for (int j = pos; j < pos + allComb[i].size(); j++) {
                    target[j] = '*';
                }
            }
        }
        if (!ok) break;
    }

    for (int i : target) {
        if (i != '*') return {};
    }

    reverse(ans.begin(), ans.end());
    return ans;
}