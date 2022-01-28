#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

void solve() {
    int N;
    cin >> N;
    vector<pair<int, int>> A(N + 2);
    for (int i = 1; i <= N; i++) {
        cin >> A[i].first >> A[i].second;
    }

    vector<int> ans = {1};
    set<int> done;
    int i = 1;
    done.insert(1);

    while (true) {
        int minnDist = INF, minnIndex = -1;
        for (int j = 1; j <= N; j++) {
            if (done.find(j) == done.end()) {
                if (min(abs(A[i].first - A[j].first), abs(A[i].second - A[j].second)) < minnDist) {
                    minnDist = min(abs(A[i].first - A[j].first), abs(A[i].second - A[j].second));
                    minnIndex = j;
                }
            }
        }

        if (minnIndex == -1) {
            break;
        }

        done.insert(minnIndex);
        ans.push_back(minnIndex);
        i = minnIndex;
    }

    int xorr = 0;
    for (int i: ans) {
        xorr ^= i;
    }
    cout << xorr << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}