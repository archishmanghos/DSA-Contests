class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        unordered_map<int, set<int>> mp;
        for(auto i : mappings){
            mp[i[0]].insert(i[1]);
        }

        for(int i = 0; i <= s.size() - sub.size(); i++){
            if(s[i] == sub[0] or s[i] == mp[sub[0]]){
                int j = i, k = 0;
                bool ok = true;
                while(k < sub.size()){
                    if(s[j] == sub[k] or mp[sub[k]].find(s[j]) != mp[sub[k]].end()){
                        j += 1, k += 1;
                        continue;
                    }
                    ok = false;
                    break;
                }
                if(ok) return true;
            }
        }

        return false;
    }
};