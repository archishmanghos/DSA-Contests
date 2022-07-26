#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n; cin >> n;
    vector<vector<int>> triangle(n);
    for (int i = 0; i < n; i++) {
        vector<int> temp(i + 1);
        for (int j = 0; j <= i; j++) {
            cin >> temp[j];
        }
        triangle[i] = temp;
    }

    vector<int> preCache(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        vector<int> curCache(n, 0);
        for (int j = i; j >= 0; j--) {
            if (i == n - 1) curCache[j] = triangle[i][j];
            else {
                curCache[j] = preCache[j] + triangle[i][j];
                if (j < n - 1) curCache[j] = min(curCache[j], preCache[j + 1] + triangle[i][j]);
            }
        }
        preCache = curCache;
    }

    cout << preCache[0];
    return 0;
}