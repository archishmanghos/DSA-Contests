class Solution {
public:
    char getChar (char a, char b) {
        if (a == 'R') {
            return b == 'G' ? 'B' : 'G';
        } else if (a == 'G') {
            return b == 'R' ? 'B' : 'R';
        }
        return b == 'R' ? 'G' : 'R';
    }
    int findMin(int n, char a[]) {
        vector<char> st;
        for (int i = 0; i < n; i++) {
            char cur = a[i];
            while (st.size() and st.back() != cur) {
                cur = getChar (st.back(), cur);
                st.pop_back();
            }
            st.push_back(cur);
        }

        int ans = st.size();
        st.clear();

        for (int i = n - 1; i >= 0; i--) {
            char cur = a[i];
            while (st.size() and st.back() != cur) {
                cur = getChar (st.back(), cur);
                st.pop_back();
            }
            st.push_back(cur);
        }

        ans = min(ans, (int)st.size());
        return ans % 2 == 1 ? 1 : ans;
    }
};