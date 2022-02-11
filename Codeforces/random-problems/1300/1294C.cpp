#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

struct primeFactor {
    int value, count;
};

vector<primeFactor> PF(int n)    //Prime Factorization
{
    vector<primeFactor> ans;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                ++cnt;
                n /= i;
            }
            ans.push_back({i, cnt});
        }
    }
    if (n > 1)
        ans.push_back({n, 1});

    return ans;
}

void solve() {
    int N;
    cin >> N;
    vector<primeFactor> v = PF(N);
    if (v.size() >= 3) {
        cout << "YES" << '\n';
        cout << v[0].value << ' ' << v[1].value << ' ';
        v[0].count -= 1;
        v[1].count -= 1;
        int rest = 1;
        for (primeFactor p: v) {
            for (int j = 1; j <= p.count; j++) {
                rest *= p.value;
            }
        }
        cout << rest << '\n';
    } else if (v.size() == 2) {
        if (v[0].count < 3 and v[1].count < 3) {
            if (v[0].count == 2 and v[1].count == 2) {
                cout << "YES" << '\n';
                cout << v[0].value << ' ' << v[0].value * v[1].value << ' ' << v[1].value << '\n';
            } else {
                cout << "NO" << '\n';
            }
            return;
        }

        cout << "YES" << '\n';
        if (v[0].count >= 3) {
            cout << v[0].value << ' ' << v[0].value * v[0].value << ' ';
            v[0].count -= 3;
        } else {
            cout << v[1].value << ' ' << v[1].value * v[1].value << ' ';
            v[1].count -= 3;
        }

        int rest = 1;
        for (primeFactor p: v) {
            for (int j = 1; j <= p.count; j++) {
                rest *= p.value;
            }
        }
        cout << rest << '\n';

    } else {
        if (v[0].count < 6) {
            cout << "NO" << '\n';
            return;
        }

        cout << "YES" << '\n';
        cout << v[0].value << ' ' << v[0].value * 2 << ' ';
        v[0].count -= 3;

        int rest = 1;
        for (int j = 1; j <= v[0].count; j++) {
            rest *= v[0].value;
        }
        cout << rest << '\n';
    }
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