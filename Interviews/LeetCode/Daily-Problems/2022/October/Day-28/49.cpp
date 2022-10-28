class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ump;
        for (string s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            ump[t].push_back(s);
        }

        vector<vector<string>> ans(ump.size());
        int j = 0;
        for (auto i : ump) {
            for (string s : i.second) {
                ans[j].push_back(s);
            }
            j += 1;
        }

        return ans;
    }
};