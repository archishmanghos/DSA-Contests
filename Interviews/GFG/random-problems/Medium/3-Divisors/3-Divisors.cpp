#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int bs(vector<int64_t>& v, int64_t x) {
        int low = 0, high = v.size() - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (v[mid] <= x) {
                ans = mid;
                low = mid + 1;
                if (v[mid] == x) {
                    break;
                }
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
    vector<int> threeDivisors(vector<long long> query, int q) {
        int maxx = 1e6;
        vector<int64_t> isPrime(maxx + 1, 1), primeSquares;
        for (int64_t i = 2; i <= maxx; i++) {
            if (isPrime[i]) {
                primeSquares.push_back(i * i);
                for (int64_t j = i * 2; j <= maxx; j += i) {
                    isPrime[j] = 0;
                }
            }
        }

        vector<int> ans(q);
        for (int i = 0; i < q; i++) {
            int idx = bs(primeSquares, query[i]);
            ans[i] = idx + 1;
        }

        return ans;
    }
};