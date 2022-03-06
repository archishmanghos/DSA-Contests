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
    int first = 0, last, zero = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        first += A[i];
        zero += A[i] == 0;
    }

    sort(A.begin() + 1, A.begin() + N + 1);
    first -= A[N];
    last = A[N];

    if (zero == N) {
        cout << 0 << '\n';
    } else if (first + 1 >= last) {
        cout << 1 << '\n';
    } else {
        cout << 1 + (last - (first + 1)) << '\n';
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