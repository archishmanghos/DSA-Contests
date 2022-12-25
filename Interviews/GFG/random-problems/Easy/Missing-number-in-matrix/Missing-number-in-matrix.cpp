#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long int MissingNo(vector<vector<int> >& matrix) {
        int n = matrix.size();
        int64_t sum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            sum = 0;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    sum = 0;
                    break;
                }
                sum += matrix[i][j];
            }
            if (sum != 0) break;
        }

        vector<int> pos0(2);
        for (int i = 0; i < n; i++) {
            int64_t tempSum = 0, pos = -1;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) pos = j;
                tempSum += matrix[i][j];
            }

            if (pos != -1) {
                if (tempSum >= sum) return -1;
                pos0[0] = i;
                pos0[1] = pos;
                ans = sum - tempSum;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            int64_t tempSum1 = 0, tempSum2 = 0;
            for (int j = 0; j < n; j++) {
                if (i == pos0[0] and j == pos0[1]) tempSum1 += ans;
                else tempSum1 += matrix[i][j];
                if (i == pos0[1] and j == pos0[0]) tempSum2 += ans;
                else tempSum2 += matrix[j][i];
            }

            if (tempSum1 != sum or tempSum2 != sum) return -1;
        }

        int64_t tempSum1 = 0, tempSum2 = 0;
        for (int i = 0; i < n; i++) {
            if (i == pos0[0] and i == pos0[1]) tempSum1 += ans;
            else tempSum1 += matrix[i][i];
            if (i == pos0[0] and (n - i - 1) == pos0[1]) tempSum2 += ans;
            else tempSum2 += matrix[i][n - i - 1];
        }

        if (tempSum1 != sum or tempSum2 != sum) return -1;
        return ans;
    }
};