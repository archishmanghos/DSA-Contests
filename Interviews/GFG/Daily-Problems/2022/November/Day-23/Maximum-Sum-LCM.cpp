#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long int maxSumLCM(int n) {
        long long int ans = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                ans += i;
                if (n / i != i) {
                    ans += n / i;
                }
            }
        }

        return ans;
    }
};