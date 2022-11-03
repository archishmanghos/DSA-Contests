class Solution {
public:
    string oddString(vector<string>& words) {
        map<vector<int>, int> mp;
        map<vector<int>, string> mp1;
        for (string s : words) {
            vector<int> cnt;
            for (int i = 1; i < s.size(); i++) {
                cnt.push_back(s[i] - s[i - 1]);
            }
            mp[cnt] += 1;
            mp1[cnt] = s;
        }

        for (auto it : mp) {
            if (it.second == 1) return mp1[it.first];
        }

        return "-1";
    }
};