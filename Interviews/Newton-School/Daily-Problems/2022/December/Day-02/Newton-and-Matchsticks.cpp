#include <bits/stdc++.h>
using namespace std;

map<int, string> cache;

string getMax(string s, string t) {
    if (s.size() != t.size()) {
        return s.size() > t.size() ? s : t;
    }
    return max(s, t);
}

string dp(int n, int m, vector<vector<int>>& a) {
    if (n == 0) {
        return "";
    }
    if (cache.find(n) != cache.end()) {
        return cache[n];
    }

    string ans = "0";
    for (int i = 0; i < m; i++) {
        if (a[i][0] <= n) {
            char c = (a[i][1] + '0');
            string x = dp(n - a[i][0], m, a);
            if (x == "0")
                continue;
            ans = getMax(ans, (x + c));
        }
    }

    return cache[n] = ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int sticks[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> a[i][1];
        a[i][0] = sticks[a[i][1]];
    }

    cout << dp(n, m, a);
    return 0;
}