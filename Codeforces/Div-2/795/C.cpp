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

int T, N, K;
string S;

int calculateValue(){
	int ans = 0;
	for(int i = 0; i < N - 1; i++){
		if(S[i] == '0' and S[i + 1] == '0') continue;
		else if(S[i] == '0' and S[i + 1] == '1') ans += 1;
		else if(S[i] == '1' and S[i + 1] == '0') ans += 10;
		else ans += 11;
	}
 
	return ans;
}

void solve() {
	cin >> N >> K >> S;
	int last1 = -1;
	for(int i = N - 1; i >= 0; i--){
		if(S[i] == '1'){
			last1 = i;
			break;
		}
	}

	if(last1 == -1){
		cout << 0 << '\n';
		return;
	}

	if(last1 < N - 1){
		if(N - 1 - last1 <= K){
			swap(S[N - 1], S[last1]);
			K -= N - 1 - last1;
		}
	}

	int first1 = -1;
	for(int i = 0; i < N; i++){
		if(S[i] == '1'){
			first1 = i;
			break;
		}
	}

	if(first1 > 0 and first1 != N - 1){
		if(first1 <= K) swap(S[first1], S[0]);
	}

	cout << calculateValue() << '\n';
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