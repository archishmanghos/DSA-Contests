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

int Q, type, X, C;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    set<int> s;
    map<int, int> mp;
    cin >> Q;
    while(Q--){
    	cin >> type;
    	if(type == 1){
    		cin >> X;
    		s.insert(X);
    		if(mp.find(X) != mp.end()) mp[X] += 1;
    		else mp[X] = 1;
    	}else if(type == 2){
    		cin >> X >> C;
    		if(mp.find(X) != mp.end()) mp[X] = max(0LL, mp[X] - C);

    		if(mp.find(X) != mp.end() and mp[X] == 0) s.erase(X);
    	}else{
    		int maxValue = *s.rbegin(), minValue = *s.begin();
    		cout << (maxValue - minValue) << '\n';
    	}
    }

    return 0;
}