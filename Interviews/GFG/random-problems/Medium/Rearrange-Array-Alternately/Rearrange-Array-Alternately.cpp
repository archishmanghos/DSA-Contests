#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void rearrange(long long* arr, int n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = arr[i];
        }

        int j = 0, k = n - 1;
        for (int i = 0; i < n; i++) {
            arr[i] = (i % 2 == 0 ? a[k--] : a[j++]);
        }
    }
};