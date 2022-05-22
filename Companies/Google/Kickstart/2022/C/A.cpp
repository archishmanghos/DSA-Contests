#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <D:/archishmanghos/Practice/Online_Judges/archiDebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N;
string S;

void solve() {
    cin >> N >> S;
    int digit = 0, lower = 0, upper = 0, special = 0;
    for(char c : S){
    	digit += (c >= '0' and c <= '9');
    	lower += (c >= 'a' and c <= 'z');
    	upper += (c >= 'A' and c <= 'Z');
    	special += (c == '#' or c == '@' or c == '*' or c == '&');
    }

    if(!digit) S += '1';
    if(!lower) S += 'a';
    if(!upper) S += 'A';
    if(!special) S += '#';

    if(S.size() < 7) {
    	int extra = 7 - S.size();
    	for(int i = 1; i <= extra; i++) S += '1';
    }

	cout << S << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}