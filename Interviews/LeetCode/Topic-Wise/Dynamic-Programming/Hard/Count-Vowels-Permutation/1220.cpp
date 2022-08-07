int add(int a, int b, int mod = 1e9 + 7) {
    return ((a % mod) + (b % mod)) % mod;
}

int countVowelPermutation(int n) {
    // a = 1
    // e = 2
    // i = 3
    // o = 4
    // u = 5

    vector<int> preCache(6, 0);
    for (int i = n - 1; i >= 0; i--) {
        vector<int> curCache(6, 0);
        for (int j = 5; j >= 0; j--) {
            if (i == n - 1) {
                if (j == 0) curCache[j] = 5;
                else if (j % 4 == 1) curCache[j] = 1;
                else if (j % 2 == 0) curCache[j] = 2;
                else curCache[j] = 4;
            } else if (j == 0) {
                for (int k = 1; k <= 5; k++) {
                    curCache[j] = add(curCache[j], preCache[k]);
                }
            } else if (j == 1) {
                curCache[j] = add(curCache[j], preCache[2]);
            } else if (j == 2) {
                curCache[j] = add(curCache[j], add(preCache[1], preCache[3]));
            } else if (j == 3) {
                for (int k = 1; k <= 5; k++) {
                    if (k != 3) {
                        curCache[j] = add(curCache[j], preCache[k]);
                    }
                }
            } else if (j == 4) {
                curCache[j] = add(curCache[j], add(preCache[3], preCache[5]));
            } else {
                curCache[j] = add(curCache[j], preCache[1]);
            }
        }
        preCache = curCache;
    }

    return preCache[0];
}