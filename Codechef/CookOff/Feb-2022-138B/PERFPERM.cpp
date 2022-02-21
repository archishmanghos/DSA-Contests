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
    int N, K;
    cin >> N >> K;

    if (N == 1) {
        cout << N << ' ';
    } else if (N == 2) {
        if (K == 1) {
            cout << 2 << ' ' << 1;
        } else {
            cout << 1 << ' ' << 2;
        }
    } else if (N == 3) {
        if (K == 1) {
            cout << 1 << ' ' << 3 << ' ' << 2;
        } else if (K == 2) {
            cout << 2 << ' ' << 1 << ' ' << 3;
        } else {
            cout << 1 << ' ' << 2 << ' ' << 3;
        }
    } else {
        if (K < (N - 1)) {
            for (int i = 1; i <= K; i++) {
                cout << i << ' ';
            }
            int rem = (N - K);
            if (rem % 2) {
                if (rem - 3 > 0) {
                    int upto = rem - 3;
                    for (int i = K + 1; i <= (K + upto); i += 2) {
                        cout << i + 1 << ' ' << i << ' ';
                    }
                }
                vector<int> v = {N - 2, N - 1, N};
                do {
                    debug(v)
                    if (v[0] % (N - 2) != 0 and v[1] % (N - 1) != 0 and v[2] % N != 0) {
                        cout << v[0] << ' ' << v[1] << ' ' << v[2];
                        break;
                    }
                } while (next_permutation(v.begin(), v.end()));
            } else {
                for (int i = K + 1; i <= N; i += 2) {
                    cout << i + 1 << ' ' << i << ' ';
                }
            }
        } else if (K == N - 1) {
            if (N % 2) {
                for (int i = 1; i <= N; i++) {
                    if (i == 2) {
                        cout << N - 1 << ' ';
                    } else if (i == N - 1) {
                        cout << 2 << ' ';
                    } else {
                        cout << i << ' ';
                    }
                }
            } else {
                for (int i = 1; i <= N; i++) {
                    if (i == 2) {
                        cout << N << ' ';
                    } else if (i == N) {
                        cout << 2 << ' ';
                    } else {
                        cout << i << ' ';
                    }
                }
            }
        } else {
            for (int i = 1; i <= N; i++) {
                cout << i << ' ';
            }
        }
    }


    cout << '\n';
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