#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);

    int totSum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        totSum += a[i];
    }

    sort(a.begin(), a.end());
    int sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        sum += a[i];
        int steps = (sum + x + y - 1) / (x + y);
        int next = i > 0 ? a[i - 1] : 0;
        if (steps >= (next + y - 1) / y) {
            return steps;
        }
    }

    return 0;
}