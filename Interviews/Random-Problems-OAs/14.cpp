#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int setval(string s, int k) {

    int n = s.size();

    vector<int>originalPre(n, 0), samePre(n, 0), originalSuf(n, 0), sameSuf(n, 0);

    int cnt = 1;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (i - 1 >= 0 && s[i] != s[i - 1]) {
            sum += to_string(cnt).size() + 1;
            cnt = 1;
            originalPre[i] = sum;
        }
        else if (i - 1 >= 0) {
            cnt++;
            originalPre[i] = sum;
        }
        samePre[i] = cnt;
    }

    cnt = 1; sum = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (i + 1 < n && s[i] != s[i + 1]) {
            cnt = 1;
            sum += to_string(cnt).size() + 1;
            originalSuf[i] = sum;
        }
        else if (i + 1 < n) {
            cnt++;
            originalSuf[i] = sum;
        }
        sameSuf[i] = cnt;
    }

    int ans = INT_MAX;

    // for (auto it : originalPre)cout << it << " ";

    for (int i = 0; i < n; i++) {
        if (i + k - 1 < n) {
            int temp = 0;
            if (i - 1 >= 0)temp += originalPre[i - 1];
            if (i + k < n)temp += originalSuf[i + k];

            if (i - 1 >= 0 && i + k < n) {
                if (s[i - 1] == s[i + k]) {
                    temp += to_string(samePre[i - 1] + sameSuf[i + k]).size() + 1;
                }
                else {
                    temp += to_string(samePre[i - 1]).size() + to_string(sameSuf[i + k]).size() + 2;
                }
            }
            else if (i - 1 >= 0) {
                temp += to_string(samePre[i - 1]).size() + 1;
            }
            else if (i + k < n) {
                temp += to_string(sameSuf[i + k]).size() + 1;
            }

            ans = min(ans, temp);

        }
    }

    return ans;



}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int k;
    cin >> s >> k;

    cout << setval(s, k);
    return 0;
}