#include <bits/stdc++.h>
using namespace std;

int findRowK(vector< vector< int> > &mat) {
    int N = mat.size();
    for (int i = 0; i < N; i++) {
        int zero = 1;
        for (int j = 0; j < N; j++) {
            if (j != i) {
                zero &= mat[i][j] == 0;
                if (!zero) break;
            }
        }

        if (zero) {
            int one = 1;
            for (int j = 0; j < N; j++) {
                if (i != j) {
                    one &= mat[j][i] == 1;
                    if (!one) break;
                }
            }

            if (one) return i;
        }
    }

    return -1;
}