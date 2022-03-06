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
    int N;
    cin >> N;
    vector<int> A(N + 2);
    int zero = 0, last1 = 1, last11 = N;
    bool ok = true;
    bool flag = false;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        if (A[i] == 0) {
            if (!ok) {
                flag = true;
            }
            zero += 1;
        } else {
            if (zero) {
                ok = false;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (A[i] == 1) {
            last1 = i;
        } else {
            break;
        }
    }

    for (int i = N; i >= 1; i--) {
        if (A[i] == 1) {
            last11 = i;
        } else {
            break;
        }
    }

    if (flag) {
        cout << last11 - last1 << '\n';
    } else if (zero) {
        cout << zero + 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
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