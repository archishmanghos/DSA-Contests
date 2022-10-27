class Solution {
public:
    vector<int> leafNodes (int arr[], int N) {
        vector<int> st, ans;
        for (int i = 0, j = 1; j < N; i++, j++) {
            if (arr[j] < arr[i]) {
                st.push_back(arr[i]);
            } else {
                bool leaf = 0;
                while (st.size() and arr[j] > st.back()) {
                    st.pop_back();
                    leaf = 1;
                }

                if (leaf) ans.push_back(arr[i]);
            }
        }

        ans.push_back(arr[N - 1]);
        return ans;
    }
};