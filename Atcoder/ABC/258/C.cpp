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

int N, Q, type, pos;
string S;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> N >> Q >> S;
    int rotation = 0;
    while(Q--){
    	cin >> type >> pos;
    	if(type == 1) rotation = (rotation + pos) % N;
    	else{
    		int newPos = ((pos - 1) + (N - rotation)) % N;
    		cout << S[newPos] << '\n';
    	}
    }

    return 0;
}