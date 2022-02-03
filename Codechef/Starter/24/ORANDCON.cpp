#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

string integertobinary(int x) {
    string ans = "";
    while (x > 0) {
        ans += (x % 2) + '0';
        x >>= 1;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int binarytointeger(string x) {
    int ans = 0, m = 1;
    for (int i = x.size() - 1; i >= 0; i--) {
        ans += (x[i] - '0') * m;
        m <<= 1;
    }
    return ans;
}

void solve() {
    int X;
    cin >> X;
    string bin = integertobinary(X);
    string A = "", B = "", C = "";
    int pos = 0;

    if (X > 1 and (X & (X - 1)) == 0) {
        cout << X << ' ' << X + 1 << ' ' << X + 2 << '\n';
        return;
    }
    if (X == 1) {
        cout << "0 1 3" << '\n';
        return;
    }

    for (int i = 0; i < bin.size(); i++) {
        if (bin[i] == '1') {
            if (pos % 3 == 0) {
                A += '0';
                B += '1';
                C += '1';
            } else if (pos % 3 == 1) {
                A += '1';
                B += '0';
                C += '1';
            } else {
                A += '1';
                B += '1';
                C += '0';
            }
            pos += 1;
        } else {
            A += '0';
            B += '0';
            C += '0';
        }
    }

    cout << binarytointeger(A) << ' ' << binarytointeger(B) << ' ' << binarytointeger(C) << '\n';
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