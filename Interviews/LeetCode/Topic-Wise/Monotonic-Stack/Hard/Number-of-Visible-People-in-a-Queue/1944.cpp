#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> st, ans (heights.size(), 0);
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (st.size() and heights[i] > st.back()) {
                ans[i] += 1;
                st.pop_back();
            }

            ans[i] += st.size() ? 1 : 0;
            st.push_back(heights[i]);
        }

        return ans;
    }
};