#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <D:/archishmanghos/Practice/Online_Judges/Clion/archiDebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    bool neg = (n < 0 ? true : false);
    n = abs(n);
    if (neg) {
        if (n % 10) {
            cout << -(n / 10 + 1);
        } else {
            cout << -(n / 10);
        }
    } else {
        cout << (n / 10);
    }

    return 0;
}