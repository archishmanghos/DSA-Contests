#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

vector<string> allNumbers;

string integertostring(int x) {
    string ans = "";
    while (x > 0) {
        ans += (x % 10) + '0';
        x /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int stringtointeger(string x) {
    int ans = 0, j = 1;

    for (int i = x.size() - 1; i >= 0; i--) {
        ans += (x[i] - '0') * j;
        j *= 10;
    }

    return ans;
}

void solve() {
    string N;
    cin >> N;

    int ans = N.size() + 1;
    string ans1 = N;
    for (int i = 0; i < allNumbers.size(); i++) {
        if (stringtointeger(allNumbers[i]) <= 1000) {
            int N1 = allNumbers[i].size();
            string temp1 = N;
            string temp2 = allNumbers[i];
            if (N1 == N.size()) {
                int count = 0;
                for (int j = 0; j < N1; j++) {
                    count += temp1[j] != temp2[j];
                }
                if (count < ans) {
                    ans = count;
                    ans1 = allNumbers[i];
                }
            }
        } else {
            break;
        }
    }

    cout << ans1 << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    for (int i = 10; i <= mxN; i++) {
        if (i % 7 == 0) {
            allNumbers.push_back(integertostring(i));
        }
    }

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}