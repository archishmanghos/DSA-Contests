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

int N, M;
string S;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> N >> M;
    pair<int, int> coordinate1 = {-1, -1}, coordinate2 = {-1, -1};
    for(int i = 1; i <= N; i++){
    	cin >> S;
    	for(int j = 0; j < M; j++){
    		if(S[j] == 'o'){
    			if(coordinate1.first == -1) coordinate1 = {i - 1, j};
    			else coordinate2 = {i - 1, j};
    		}
    	}
    }

    cout << abs(coordinate1.first - coordinate2.first) + abs(coordinate1.second - coordinate2.second);

    return 0;
}