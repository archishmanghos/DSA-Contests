vector<int> leftSmaller(int n, int a[]) {
    vector<int> st, ans;
    for (int i = 0; i < n; i++) {
        while (st.size() > 0 and a[i] <= st.back()) {
            st.pop_back();
        }
        if (st.size() == 0) ans.push_back(-1);
        else ans.push_back(st.back());
        st.push_back(a[i]);
    }

    return ans;
}