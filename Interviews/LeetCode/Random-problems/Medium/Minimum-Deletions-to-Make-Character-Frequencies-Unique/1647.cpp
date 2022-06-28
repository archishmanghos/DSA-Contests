class Solution {
public:
    int minDeletions(string s) {
        vector<int> count(26, 0);
        for (char c : s)
            count[c - 'a'] += 1;
        set<int> cnts;
        for (int i = 0; i < 26; i++) {
            if (cnts.find(count[i]) != cnts.end()) {
                int maxToChange=0;
                for(int j=0; j<26; j++){
                    if()
                }
            }
        }
    }
};