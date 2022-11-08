class Solution {
   public:
    string makeGood(string s) {
        string ans = "";
        for (char c : s) {
            if (ans.size() == 0 or abs(int(c) - int(ans.back())) != 32) {
                ans.push_back(c);
            } else {
                ans.pop_back();
            }
        }

        return ans;
    }
};