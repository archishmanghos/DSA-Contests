class Solution {
   public:
    string robotWithString(string s) {
        vector<int> origCnt(26, 0), curCnt(26, 0);
        vector<char> st;
        for (char c : s) {
            origCnt[c - 'a'] += 1;
            curCnt[c - 'a'] += 1;
        }

        string ans = "";
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            int ch = s[i] - 'a';
            curCnt[ch] -= 1;
            if (ch == j) {
                ans += s[i];
            } else {
                st.push_back(s[i]);
            }
            if (curCnt[j] == 0) {
                while (j < 26 and curCnt[j] == 0) {
                    ++j;
                }
                while (st.size() > 0 and (st.back() - 'a') <= j) {
                    ans += st.back();
                    st.pop_back();
                }
            }
        }

        return ans;
    }
};