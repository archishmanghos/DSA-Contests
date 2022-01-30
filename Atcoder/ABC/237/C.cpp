#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

bool isPal(string S) {
    int i = 0, j = S.size() - 1;
    while (i < j) {
        if (S[i] != S[j]) {
            return false;
        }
        i += 1;
        j -= 1;
    }
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string S;
    cin >> S;
    int N = S.size(), firstPos = -1, lastPos = -1, cnt = 0;

    for (int i = N - 1; i >= 0; i--) {
        if (S[i] != 'a') {
            lastPos = i;
            break;
        } else {
            cnt += 1;
        }
    }

    for (int i = 0; i < N; i++) {
        if (cnt == 0 or S[i] != 'a') {
            firstPos = i;
            break;
        } else {
            cnt -= 1;
        }
    }

    string S1 = "";
    for (int i = firstPos; i <= lastPos; i++) {
        S1 += S[i];
    }
    if (isPal(S1)) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}