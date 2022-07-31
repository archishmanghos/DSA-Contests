#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int N, prev, prevToPrev; cin >> N;
    prevToPrev = 0, prev = 1;

    for (int i = 2; i <= N; i++) {
        int curFib = prev + prevToPrev;
        prevToPrev = prev;
        prev = curFib;
    }

    cout << prev;

    return 0;
}