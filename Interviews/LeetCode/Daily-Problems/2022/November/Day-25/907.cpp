#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int add(int a, int b, int p = 1e9 + 7) {
        int c = a + b;
        if (c >= p) {
            c -= p;
        }
        return c;
    }

    int sub(int a, int b, int p = 1e9 + 7) {
        int c = a - b;
        if (c < 0) {
            c += p;
        }
        return c;
    }

    int mul(int a, int b, int p = 1e9 + 7) {
        return (a * (int)1 * b) % p;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<vector<int>> st;
        st.push_back({0, -1});
        int prefSum = 0, ans = 0;

        for (int i = 0; i < arr.size(); i++) {
            while (st.size() > 0 and arr[i] < st.back()[0]) {
                vector<int> last = st.back();
                st.pop_back();
                prefSum = sub(prefSum, mul(last[0], sub(last[1], st.back()[1])));
            }

            ans = add(ans, add(prefSum, mul(arr[i], sub(i, st.back()[1]))));
            prefSum = add(prefSum, mul(arr[i], sub(i, st.back()[1])));
            st.push_back({arr[i], i});
        }

        return ans;
    }
};

// Explanation of above logic:

// 3 1 4 2

// [(3, 0)]        Sum = 3
// [(1, 1)]        Sum = 3 + 1 * 2 = 5
// [(1, 1), (4, 2)]    Sum = 5 + 1 * 2 + 4 = 11
// [(1, 1), (2, 3)]    Sum = 11 + 1 * 2 + 2 * 2 = 17

// 3 1 2 4

// [(3, 0)]            Sum = 3 * 1 = 3
// [(1, 1)]            Sum = 3 + 1 * 2 = 5
// [(1, 1), (2, 2)]        Sum = 5 + 1 * 2 + 2 * 1 = 9
// [(1, 1), (2, 2), (4, 3)]    Sum = 9 + 1 * 2 + 2 * 1 + 4 * 1 = 17