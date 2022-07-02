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

int K;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> K;
    int hour = K / 60;
    int min = K % 60;

    if(hour) cout << "22:";
    else cout << "21:";

    cout << (char)((min / 10) + '0') << (char)((min % 10) + '0') << '\n';

    return 0;
}