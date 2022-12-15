#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sod (int N) {
        int sum = 0;
        while (N > 0) {
            sum += N % 10;
            N /= 10;
        }

        return sum;
    }

    string BalancedString(int N) {
        string ans (N, '.');
        int digitSum = sod (N);
        int repeat = N / 26;
        N %= 26;

        for (int i = 0; i < repeat; i++) {
            for (int j = 0; j < 26; j++) {
                ans[i * 26 + j] = (j + 'a');
            }
        }

        if (N & 1) {
            if (digitSum & 1) {
                for (int i = 0 ; i < ((N - 1) / 2); i++) {
                    ans[repeat * 26 + i] = (i + 'a');
                }
                for (int i = 0; i < ((N + 1) / 2); i++) {
                    ans[repeat * 26 + ((N - 1) / 2 + i)] = ((25 - (N - 1) / 2 + i) + 'a');
                }
            } else {
                for (int i = 0 ; i < ((N + 1) / 2); i++) {
                    ans[repeat * 26 + i] = (i + 'a');
                }
                for (int i = 0; i < ((N - 1) / 2); i++) {
                    ans[repeat * 26 + ((N + 1) / 2 + i)] = ((25 - (N - 1) / 2 + 1 + i) + 'a');
                }
            }
        } else {
            for (int i = 0 ; i < (N / 2); i++) {
                ans[repeat * 26 + i] = (i + 'a');
            }
            for (int i = 0; i < (N / 2); i++) {
                ans[repeat * 26 + (N / 2 + i)] = ((25 - (N - 1) / 2 + i) + 'a');
            }
        }

        return ans;
    }
};