#include <bits/stdc++.h>
using namespace std;

int powerOfPower(int A, int B, int C, int M) {
    auto binExp = [](int a, int b, int MOD) {
        int answer = 1;
        while (b) {
            if (b & 1) answer = (1ll * answer * a) % MOD;
            b /= 2;
            a = (1ll * a * a) % MOD;
        }

        return answer;
    };

    int y = binExp(B, C, M - 1);
    return binExp(A, y, M);
}