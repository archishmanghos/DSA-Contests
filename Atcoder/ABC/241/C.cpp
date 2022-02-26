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

    int N;
    cin >> N;
    vector<string> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
            for (int k = 0; k < 6; k++) {
                count1 += (i + 6 <= N and A[i + k][j] == '#');
                count2 += (j + 6 <= N and A[i][j + k] == '#');
                count3 += (i + 6 <= N and j + 6 <= N and A[i + k][j + k] == '#');
                count4 += (i + 6 <= N and j - 5 >= 0 and A[i + k][j - k] == '#');

                if (count1 >= 4 or count2 >= 4 or count3 >= 4 or count4 >= 4) {
                    cout << "Yes" << '\n';
                    return 0;
                }
            }
        }
    }

    cout << "No";

    return 0;
}