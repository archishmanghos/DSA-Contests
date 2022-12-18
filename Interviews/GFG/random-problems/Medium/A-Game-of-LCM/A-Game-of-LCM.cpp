#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxGcd(int N) {
        long long ans = N * (N - 1);
        int k = 2;
        for (int i = N - 2; i >= 1; i--) {
            if (__gcd (ans, 1LL * i) == 1LL) {
                ans *= i;
                k -= 1;
                if (k == 0) {
                    break;
                }
            }
        }

        return ans;
    }
};