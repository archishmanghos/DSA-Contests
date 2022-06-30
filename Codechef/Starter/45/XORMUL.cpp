#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, A, B;

void solve() {
    
    cin >> N >> A >> B;
    int ans = 0;
    bool unsetA = false, unsetB = false;
    for(int i = N - 1; i >= 0; i--){
    	int bitA = (A & (1 << i));
    	int bitB = (B & (1 << i));
    	if(bitA == bitB) {
    		if(!bitA and !bitB) ans |= (1 << i);
    	}
    	else{
    		if(!unsetA and !unsetB) {
    			ans |= (1 << i);
    			if(bitA) unsetA = true;
    			else unsetB = true;
    		}else{
    			if(unsetA){
    				if(!bitA) ans |= (1 << i);
    			}else{
    				if(!bitB) ans |= (1 << i);
    			}
    		}
    	}
    }

    cout << ans << '\n';
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
        solve();

    return 0;
}