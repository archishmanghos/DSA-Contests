#include <bits/stdc++.h>
using namespace std;

string buildLowestNumber(string num, int k) {
    vector<char> st;
    for (int i = 0; i < num.size(); i++) {
        while (k > 0 and st.size() > 0 and st.back() > num[i]) {
            st.pop_back();
            k -= 1;
        }

        st.push_back(num[i]);
    }

    while (k--) {
        st.pop_back();
    }

    string ans = "";
    for (int i = 0; i < st.size(); i++) {
        if (ans.size() == 0 and st[i] == '0') {
            continue;
        }

        ans += st[i];
    }

    if (ans.size() == 0) {
        ans += '0';
    }
    return ans;
}