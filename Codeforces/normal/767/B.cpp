#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T;

void solve()
{
    int L, R, K;
    cin >> L >> R >> K;

    if(L == R){
    	cout << (L == 1 ? "NO" : "YES") << '\n';
    }
    else{
    	int odd = 0, parL = L % 2, parR = R % 2;
    	if(parL == parR){
    		if(parL == 1){
    			odd = (R - L) / 2 + 1;
    		}
    		else{
    			odd = (R - L) / 2;
    		}
    	}
    	else{
    		odd = (R - L) / 2 + 1;
    	}

    	if(odd <= K){
    		cout << "YES" << '\n';
    	}
    	else{
    		cout << "NO" << '\n';
    	}
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
        solve();

    return 0;
}