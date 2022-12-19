#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int spf[100100];

    void sieve () {
        for (int i = 1; i <= 100000; i++) {
            spf[i] = i;
        }

        for (int i = 2; i * i <= 100000; i++) {
            if (spf[i] == i) {
                for (int j = 2 * i; j <= 100000; j += i) {
                    spf[j] = min (spf[j], i);
                }
            }
        }
    }

    int getPf (int n) {
        int ans = 0;
        while (n > 1) {
            ans += spf[n];
            n /= spf[n];
        }

        return ans;
    }

    int smallestValue(int n) {
        sieve();
        int n1 = n;
        while (n != spf[n]) {
            n = getPf (n);
            if (n == n1) {
                break;
            }
            n1 = n;
        }

        return n;
    }
};