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

void solve() {
    int N, A;
    cin >> N;
    int prevOdd = -1, prevEven = -1;
    bool ans = true;
    for (int i = 1; i <= N; i++) {
        cin >> A;
        if ((A & 1) and A >= prevOdd) {
            prevOdd = A;
        } else if ((A % 2 == 0) and A >= prevEven) {
            prevEven = A;
        } else {
            ans = false;
        }
    }

    cout << (ans ? "Yes" : "No") << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}