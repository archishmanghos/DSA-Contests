#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;
    a += b;
    if (a >= 15) {
        if (b >= 8) {
            cout << 1;
        } else if (b >= 3) {
            cout << 2;
        } else {
            cout << 3;
        }
    } else if (a >= 10) {
        if (b >= 3) {
            cout << 2;
        } else {
            cout << 3;
        }
    } else if (a >= 3) {
        cout << 3;
    } else {
        cout << 4;
    }
    return 0;
}