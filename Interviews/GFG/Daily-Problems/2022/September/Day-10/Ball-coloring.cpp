unsigned long long int noOfWays(unsigned long long int n) {
    vector<unsigned long long int> ans(n + 1, 2);
    for (int i = 1, j = 0; i <= n; i++, j += 2) {
        ans[i] = ans[i - 1] + j;
    }

    return ans[n];
}

// Bottom-Up DP of TC = O(n * 3 * 2) = roughly 6 * 10^5 gives TLE, don't know why?

unsigned long long int noOfWays(unsigned long long int n) {
    vector<vector<vector<unsigned long long int>>> cache(n, vector<vector<unsigned long long int>> (3, vector<unsigned long long int> (2, 0)));
    for (int index = n - 1; index >= 0; index--) {
        for (int k = 0; k <= 2; k++) {
            for (int prevColour = 1; prevColour >= 0; prevColour--) {
                if (index == n - 1) {
                    cache[index][k][prevColour] = (k > 0 ? 2 : 1);
                } else {
                    cache[index][k][prevColour] = cache[index + 1][k][prevColour];
                    if (index == 0) {
                        cache[index][k][prevColour] += cache[index + 1][k][!prevColour];
                    } else {
                        if (k > 0) {
                            cache[index][k][prevColour] += cache[index + 1][k - 1][!prevColour];
                        }
                    }
                }
            }
        }
    }
    return cache[0][2][0];
}