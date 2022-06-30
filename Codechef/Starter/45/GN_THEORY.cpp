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

int T, N, Q, U, V;

map<int, int> PF(int n)
{
	map<int, int> factors;
	for (int i = 2; i * i <= n; i++){
		if (n % i == 0){
			int cnt = 0;
			while (n % i == 0){
				++cnt;
				n /= i;
			}
			factors[i] = cnt;
		}
	}
	if (n > 1)
		factors[n] = 1;

	return factors;
}

void solve() {
    
    cin >> N >> Q;
    while(Q--){
    	cin >> U >> V;
    	int connectingNode = __gcd(U, V);
    	int ans = 0;
    	map<int, int> factoriseU = PF(U), factoriseV = PF(V), factoriseConnectingNode = PF(connectingNode);

    	for(auto i : factoriseU){
    		int x = i.first, y = i.second;
    		if(factoriseConnectingNode.find(x) != factoriseConnectingNode.end()){
    			y -= factoriseConnectingNode[x];
    		}
    		ans += x * y;
    	}

    	for(auto i : factoriseV){
    		int x = i.first, y = i.second;
    		if(factoriseConnectingNode.find(x) != factoriseConnectingNode.end()){
    			y -= factoriseConnectingNode[x];
    		}
    		ans += x * y;
    	}
    	cout << ans << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

     #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> T;
    while (T--)
        solve();

    return 0;
}