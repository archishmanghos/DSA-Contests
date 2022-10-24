struct alphanumeric {
    string name;
    int count;
};
class Solution {
public:
    vector<alphanumeric> sortedStrings(int N, vector<string> A) {
        map<string, int> mp;
        for (string s : A) {
            mp[s] += 1;
        }

        vector<alphanumeric> ans;
        for (auto i : mp) {
            ans.push_back({i.first, i.second});
        }

        return ans;
    }
};