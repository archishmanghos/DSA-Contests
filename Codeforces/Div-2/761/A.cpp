#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

void solve()
{
    string S, T;
    cin >> S >> T;
    
    if(T == "abc"){
    	int cnt[26] = {0};
	    for(char c : S){
	    	cnt[c - 'a'] += 1;
	    }

	    if(cnt[0] > 0 and cnt[1] > 0 and cnt[2] > 0){
	    	for(int i = 1; i <= cnt[0]; i++){
		    	cout << 'a';
		    }
		    for(int i = 1; i <= cnt[2]; i++){
		    	cout << 'c';
		    }
		    for(int i = 1; i <= cnt[1]; i++){
		    	cout << 'b';
		    }

		    for(int i = 3; i < 26; i++){
		    	for(int j = 1; j <= cnt[i]; j++){
		    		cout << (char)('a' + i);
		    	}
		    }
		    cout << '\n';
	    }
	    else{
	    	sort(S.begin(), S.end());
    		cout << S << '\n';
	    }
    }
    else{
    	sort(S.begin(), S.end());
    	cout << S << '\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}