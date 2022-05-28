#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e5 + 7;

string S;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> S;
    int N = S.size();
    for(int i = 1; i <= 6 / N; i++) cout << S;

    return 0;
}