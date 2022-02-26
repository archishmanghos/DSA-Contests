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

    int N, M, A;
    cin >> N >> M;
    unordered_map<int, int> mp;

    for (int i = 1; i <= N; i++) {
        cin >> A;
        mp[A] += 1;
    }

    for (int i = 1; i <= M; i++) {
        cin >> A;
        if (mp.find(A) == mp.end()) {
            cout << "No";
            return 0;
        } else {
            if (mp[A] == 0) {
                cout << "No";
                return 0;
            }
            mp[A] -= 1;
        }
    }

    cout << "Yes";

    return 0;
}