class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        for (char c: s) {
            if (ans.size() and ans.back() == c) {
                while (ans.size() > 0 and ans.back() == c) {
                    ans.pop_back();
                }
            } else {
                ans.push_back(c);   
            }
        }
        
        return ans;
    }
};