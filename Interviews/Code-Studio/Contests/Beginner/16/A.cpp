#include<bits/stdc++.h>

long long energyConsumed(vector<int> &a) {
    long long ans = 0;
    for (int i = 1; i < a.size(); i++) {
        ans += max(0LL, (a[i] - a[i - 1]) * 1LL);
    }

    return ans;
}