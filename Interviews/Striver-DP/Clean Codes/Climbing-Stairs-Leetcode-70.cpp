#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int N, prevToPrev = 1, prev = 1, mod = 1e9 + 7; cin >> N;
    for (int i = 2; i <= N; i++) {
        int curWays = ((prev % mod) + (prevToPrev % mod)) % mod;
        prevToPrev = prev, prev = curWays;
    }

    cout << prev;

    return 0;
}