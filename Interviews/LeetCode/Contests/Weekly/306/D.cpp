int power(int n) {
    int ans = 1;
    while (n--) ans *= 10;

    return ans;
}

int digitCount(int n) {
    int ans = 0;
    while (n) {
        ans += 1;
        n /= 10;
    }

    return ans;
}

int dp(int index, int ifLimitReached, int mask, int n, int k, vector<vector<vector<int>>> &cache) {
    int limit = (n / power(index)) % 10, ans = 0;
    if (index == 0) {
        if (index == k) return limit;
        if (ifLimitReached) {
            for (int i = 0; i <= limit; i++) {
                if (i == 0 and mask == 1) continue;
                if (!((mask >> i) & 1)) {
                    ans += 1;
                }
            }
        } else {
            for (int i = 0; i <= 9; i++) {
                if (i == 0 and mask == 1) continue;
                if (mask == 1 or !((mask >> i) & 1)) {
                    ans += 1;
                }
            }
        }
        return ans;
    }

    if (cache[index][ifLimitReached][mask] != -1) return cache[index][ifLimitReached][mask];

    if (index == k) {
        for (int i = 0; i <= limit; i++) {
            if (!((mask >> i) & 1)) {
                mask |= (1 << i);
                if (i < limit) {
                    ans += dp(index - 1, 0, mask, n, k, cache);
                } else {
                    ans += dp(index - 1, 1, mask, n, k, cache);
                }
                mask ^= (1 << i);
            }
        }
    } else {
        if (ifLimitReached) {
            for (int i = 0; i <= limit; i++) {
                if (mask == 1 or !((mask >> i) & 1)) {
                    mask |= (1 << i);
                    if (i < limit) {
                        ans += dp(index - 1, 0, mask, n, k, cache);
                    } else {
                        ans += dp(index - 1, 1, mask, n, k, cache);
                    }
                    mask ^= (1 << i);
                }
            }
        } else {
            for (int i = 0; i <= 9; i++) {
                if (mask == 1 or !((mask >> i) & 1)) {
                    mask |= (1 << i);
                    ans += dp(index - 1, 0, mask, n, k, cache);
                    mask ^= (1 << i);
                }
            }
        }
    }

    return cache[index][ifLimitReached][mask] = ans;
}
int countSpecialNumbers(int n) {
    int k = digitCount(n) - 1;
    vector<vector<vector<int>>> cache(10, vector<vector<int>> (2, vector<int> (3000, -1)));
    return dp(k, 0, 0, n, k, cache);
}

// Possible Bottom Up (Will Try Later, > 99 are not coming correct)

// int countSpecialNumbers(int n) {
//     int k = digitCount(n) - 1;
//     vector<vector<vector<int>>> cache(10, vector<vector<int>> (1024, vector<int> (2, 0)));

//     for (int index = 0; index <= k; index++) {
//         for (int mask = 1023; mask >= 0; mask--) {
//             for (int ifLimitReached = 1; ifLimitReached >= 0; ifLimitReached--) {
//                 int limit = (n / power(index)) % 10, ans = 0;
//                 if (index == 0) {
//                     if (index == k) cache[index][mask][ifLimitReached] = limit;
//                     else {
//                         limit = ifLimitReached ? limit : 9;
//                         for (int i = 0; i <= limit; i++) {
//                             if (i == 0 and mask == 1) continue;
//                             if (!((mask >> i) & 1)) {
//                                 cache[index][mask][ifLimitReached] += 1;
//                             }
//                         }
//                     }
//                     // cout<<index<<' '<<mask<<' '<<ifLimitReached<<' '<<cache[index][mask][ifLimitReached]<<'\n';
//                     continue;
//                 }

//                 if (index == k) {
//                     for (int i = 0; i <= limit; i++) {
//                         if (!((mask >> i) & 1)) {
//                             mask |= (1 << i);
//                             if (i < limit) {
//                                 ans += cache[index - 1][mask][0];
//                             } else {
//                                 ans += cache[index - 1][mask][1];
//                             }
//                             mask ^= (1 << i);
//                         }
//                     }
//                 } else {
//                     if (ifLimitReached) {
//                         for (int i = 0; i <= limit; i++) {
//                             if (mask == 1 or !((mask >> i) & 1)) {
//                                 mask |= (1 << i);
//                                 if (i < limit) {
//                                     ans += cache[index - 1][mask][0];
//                                 } else {
//                                     ans += cache[index - 1][mask][1];
//                                 }
//                                 mask ^= (1 << i);
//                             }
//                         }
//                     } else {
//                         for (int i = 0; i <= 9; i++) {
//                             if (mask == 1 or !((mask >> i) & 1)) {
//                                 mask |= (1 << i);
//                                 ans += cache[index - 1][mask][0];
//                                 mask ^= (1 << i);
//                             }
//                         }
//                     }
//                 }

//                 cache[index][mask][ifLimitReached] = ans;
//                 // cout<<index<<' '<<mask<<' '<<ifLimitReached<<' '<<cache[index][mask][ifLimitReached]<<'\n';
//             }
//         }
//     }

//     return cache[k][0][0];
// }