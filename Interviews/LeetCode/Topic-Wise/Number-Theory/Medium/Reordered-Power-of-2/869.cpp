bool reorderedPowerOf2(int n) {
    vector<int> cntN(10, 0);
    while (n) {
        cntN[n % 10] += 1;
        n /= 10;
    }

    for (int i = 0; i < 31; i++) {
        int j = (1 << i);
        vector<int> cnt(10, 0);
        while (j) {
            cnt[j % 10] += 1;
            j /= 10;
        }

        bool ok = true;
        for (j = 0; j <= 9; j++) {
            ok &= (cntN[j] == cnt[j]);
        }

        if (ok) return true;
    }

    return false;
}