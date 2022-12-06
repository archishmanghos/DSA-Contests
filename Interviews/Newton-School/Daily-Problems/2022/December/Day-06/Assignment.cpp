#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> A(n, vector<int>(2)), B(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> A[i][0] >> B[i][0];
        A[i][1] = B[i][1] = i;
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    if (A[0][1] == B[0][1]) {
        int time1 = A[0][0] + B[0][0];
        int time2 = max(A[0][0], B[1][0]);
        int time3 = max(A[1][0], B[0][0]);
        cout << min(time1, min(time2, time3));
    } else {
        cout << max(A[0][0], B[0][0]);
    }
    return 0;
}