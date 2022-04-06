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

int T, N, M;
string S1, S2;

bool checkIfSubsequenceExists(){
	int j = 0;
    for(int i = 0; i < N; i++){
    	if(S1[i] == S2[j]){
    		j += 1;
    	}
    	if(j == M){
    		return true;
    	}
    }
    return false;
}

void solve()
{
    cin >> N >> M >> S1 >> S2;

    if(checkIfSubsequenceExists()){
    	cout << -1 << '\n';
    	return;
    }

    vector<int> cnt(5, 0);
    for(char c : S2){
    	cnt[c - 'a'] += 1;
    }

    char freeCharacter = '0';
    for(char c = 'a'; c <= 'e'; c++){
    	if(cnt[c - 'a'] == 0){
    		freeCharacter = c;
    		break;
    	}
    }
    if(freeCharacter == '0'){
    	freeCharacter = S2[M - 1];
    }

    for(int i = 0; i < N; i++){
		if(S1[i] == '?'){
			S1[i] = freeCharacter;
		}
	}

    if(checkIfSubsequenceExists()){
    	cout << -1 << '\n';
    }else{
    	cout << S1 << '\n';
    }

}

int32_t main()
{
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