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

int T;
string S;
map<string, int> index;

void solve() {
    cin >> S;
    cout << index[S] << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	int i = 1;
	for(char c = 'a'; c <= 'z'; c++){
		for(char ch = 'a'; ch <= 'z'; ch++){
			if(c != ch){
				string s = "";
				s += c;
				s += ch;
				index[s] = i++;
			}
		}
	}

    cin >> T;
    while (T--)
        solve();

    return 0;
}