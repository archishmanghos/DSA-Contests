#include <bits/stdc++.h>
using namespace std;

int32_t main() {

    int n; cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];

    int take = 0, notTake = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= 1; j++) {
            if (i == n - 1) {
                if (j) take = 0;
                else notTake = prices[i];
            } else {
                if (j) take = max(notTake - prices[i], take);
                else notTake = max(take + prices[i], notTake);
            }
        }
    }

    cout << take;
    return 0;
}