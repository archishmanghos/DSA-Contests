vector <string> topKFrequent(vector <string> &words, int k) {
    map<string, int> mp;
    vector <pair<string, int>> v;
    vector <string> ans;
    for (string word: words) {
        mp[word] += 1;
    }
    auto comp = [](pair<string, int> a, pair<string, int> b) -> bool {
        if (a.second != b.second) {
            return a.second < b.second;
        }
        return a.first > b.first;
    };
    for (auto i: mp) {
        v.push_back(i);
    }
    sort(v.begin(), v.end(), comp);
    for (int i = v.size() - 1; i >= 0; i--) {
        if (k > 0) {
            ans.push_back(v[i].first);
            k -= 1;
        }
    }

    return ans;
}