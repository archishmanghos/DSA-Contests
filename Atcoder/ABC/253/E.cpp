#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int mod = 998244353;
const int INF = 1e5 + 7;

int N, M, K;
int cache[5005];

int dp(int value, int &index){
	if(index == N - 1) return 1;
	if(cache[value] != -1) return cache[value];

	index += 1;
	int ans = 0;
	for(int i = 1; i <= (value - K); i++){
		ans = (ans + dp(i, index)) % mod;
	}
	for(int i = (value + K); i <= M; i++){
		ans = (ans + dp(i, index)) % mod;
	}

	return cache[value] = ans % mod;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> N >> M >> K;
    memset(cache, -1, sizeof(cache));
    queue<int> q;
    for(int i = 1; i <= M; i++) queue.push(i);
    int index = 0;

    while(!q.empty()){
    	int sz = q.size();
    	if(index == N - 1) ans = (ans + q.size()) % mod;
    	for(int i = 1; i <= sz; i++){
    		int curValue = q.front();
    		q.pop();

    	}
    }

    return 0;
}