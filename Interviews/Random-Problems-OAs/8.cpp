#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int p, q;
    cin >> p >> q;

    if (q == 0) {
        cout << (p == 0 ? 0 : 1) << '\n';
        return;
    }

    if ((q & (q - 1)) == 0) {
        int steps = p == 1 ? 0 : 1;
        while (q > 1) {
            if (q & 1) {
                steps += 1;
            }
            q >>= 1;
            steps += 1;
        }

        cout << steps << '\n';
        return;
    }

    if (p > q) {
        cout << -1 << '\n';
        return;
    }

    queue<int> bfs;
    bfs.push(p);
    unordered_map<int, int> visited;
    visited[p] = 1;
    int steps = 0;

    while (!bfs.empty()) {
        int sz = bfs.size();
        for (int i = 1; i <= sz; i++) {
            int curp = bfs.front();
            bfs.pop();
            if (curp == q) {
                cout << steps << '\n';
                return;
            }
            int newQ1 = curp * curp;
            int newQ2 = curp + curp;
            if (visited.find(newQ1) == visited.end() and newQ1 <= q) {
                visited[newQ1] = 1;
                bfs.push(newQ1);
            }
            if (visited.find(newQ2) == visited.end() and newQ2 <= q) {
                visited[newQ2] = 1;
                bfs.push(newQ2);
            }
        }
        steps += 1;
    }

    cout << -1 << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tests;
    cin >> tests;
    while (tests--) {
        solve();
    }
}