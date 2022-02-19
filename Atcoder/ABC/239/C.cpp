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

struct point {
    int x, y;
};

bool ifPossible(point A, point B, point C) {
    int dist1 = (A.x - C.x) * (A.x - C.x) + (A.y - C.y) * (A.y - C.y);
    int dist2 = (B.x - C.x) * (B.x - C.x) + (B.y - C.y) * (B.y - C.y);

    return (dist1 == dist2 and dist1 == 5);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    point A, B;
    cin >> A.x >> A.y >> B.x >> B.y;

    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            point possible1 = {A.x + i, A.y + j};
            if (ifPossible(A, B, possible1)) {
                cout << "Yes";
                return 0;
            }
            point possible2 = {B.x + i, B.y + j};
            if (ifPossible(A, B, possible2)) {
                cout << "Yes";
                return 0;
            }
        }
    }

    cout << "No";

    return 0;
}