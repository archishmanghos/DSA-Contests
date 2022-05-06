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

int T, N, K;
string S;
char ch;
set<char> specialCharacter;

void solve() {
	specialCharacter.clear();
  	cin >> N >> S;
  	cin >> K;
  	for(int i = 1; i <= K; i++){
  		cin >> ch;
  		specialCharacter.insert(ch);
  	}

  	int ans = 0, preIndex = 0;
  	for(int i = 0; i < N; i++){
  		if(specialCharacter.find(S[i]) != specialCharacter.end()){
  			ans = max(ans, i - preIndex);
  			preIndex = i;
  		}
  	}

  	cout << ans << '\n';
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