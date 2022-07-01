int numSubsets(int n, vector<int> &a) {
    int maxEl = 0;
    for(int i : a){
        maxEl = max(maxEl, i);
    }

    int countMax = 0;
    for(int i : a){
        countMax += i == maxEl;
    }

    int ans = 1, mod = 1e9 + 7;
    while(countMax--) {
        ans = ((ans % mod) * 2) % mod;
    }
    return ans - 1;
}
