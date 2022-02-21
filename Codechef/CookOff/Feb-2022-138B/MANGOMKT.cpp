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

    int N, M, U, V, A, Q;
    char type;

    cin >> N >> M;
    int neighbours = M, total = N * (N - 1) / 2, cost = 0;
    debug(total)
    for (int i = 1; i <= N; i++) {
        cin >> A;
        cost += A;
    }
    for (int i = 1; i <= M; i++) {
        cin >> U >> V;
    }

    cin >> Q;
    while (Q--) {
        cin >> type;
        if (type == '?') {
            cout << cost + neighbours * 2 - total << '\n';
        } else {
            cin >> U >> V;
            neighbours += (type == '+' ? 1 : -1);
        }
    }

    return 0;
}