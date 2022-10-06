map<string, set<pair<int, string>>> mp;
string largeVal;
TimeMap() {
    mp.clear();
    for (int i = 1; i <= 105; i++) {
        largeVal += 'z';
    }
}

void set(string key, string value, int timestamp) {
    mp[key].insert({timestamp, value});
}

string get(string key, int timestamp) {
    if (mp.find(key) != mp.end()) {
        auto ub = mp[key].upper_bound({timestamp, largeVal});
        if (ub == mp[key].begin()) return "";
        ub--;
        return (*ub).second;
    } else {
        return "";
    }
}