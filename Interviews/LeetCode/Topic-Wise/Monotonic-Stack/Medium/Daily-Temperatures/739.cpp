#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> st, ans(n);
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() > 0 and temperatures[i] >= temperatures[st.back()]) {
                st.pop_back();
            }

            if (st.size() > 0) {
                ans[i] = st.back() - i;
            } else {
                ans[i] = 0;
            }

            st.push_back(i);
        }

        return ans;
    }
};