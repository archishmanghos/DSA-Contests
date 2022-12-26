#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int64_t binToInt(string s) {
        int64_t ans = 0, j = 1;
        while (s.size() > 0) {
            ans += (s.back() - '0') * j;
            j <<= 1;
            s.pop_back();
        }

        return ans;
    }

    int64_t helper (string s, int bits, int64_t L, int64_t R, int sz) {
        if (s.size() == sz) {
            int64_t a = binToInt (s);
            return bits == 0 and a >= L and a <= R;
        }

        int64_t ans = helper (s + '0', bits, L, R, sz);
        if (bits) ans += helper (s + '1', bits - 1, L, R, sz);
        return ans;
    }

    int64_t solve(int64_t l, int64_t r) {
        int sz = 0;
        for (int i = 63; i >= 0; i--) {
            if ((r >> i) & 1) {
                sz = i + 1;
                break;
            }
        }

        return helper ("", 3, l, r, sz);
    }

};