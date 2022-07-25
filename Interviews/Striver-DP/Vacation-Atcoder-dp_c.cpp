#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n; cin >> n;
    vector<vector<int>> points(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> points[i][j];
        }
    }

    vector<int> cache(3, 0);
    for (int i = n - 1; i >= 0; i--) {
        vector<int> curCache(3, 0);
        for (int lastTask = 0; lastTask < 3; lastTask++) {
            for (int curTask = 0; curTask < 3; curTask++) {
                if (i > 0) {
                    if (lastTask != curTask) {
                        curCache[lastTask] = max(curCache[lastTask], cache[curTask] + points[i][lastTask]);
                    }
                } else {
                    curCache[lastTask] = max(curCache[lastTask], cache[curTask] + points[i][lastTask]);
                }
            }
        }
        cache = curCache;
    }

    int ans = 0;
    for (int i = 0; i < 3; i++) {
        ans = max(ans, cache[i]);
    }

    cout << ans;
    return 0;
}