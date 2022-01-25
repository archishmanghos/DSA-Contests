#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T;

void solve()
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    char pre = S[0];
    string ans = "";
    ans += S[0];
    if(N > 1){
    	if(S[0] != S[1]){
    		for(int i = 1; i < N; i++){
		    	if(S[i] < pre){
		    		ans += S[i];
		    		pre = S[i];
		    	}
		    	else if(S[i] == pre){
		    		int j = i;
		    		string temp = "";
		    		while(j < N){
		    			if(S[j] != S[i]){
		    				break;
		    			}
		    			temp += S[j];
		    			j += 1;
		    		}
		    		ans += temp;
		    		if(S[j] < pre){
		    			i = j - 1;
		    			pre = S[j - 1];
		    		}
		    		else{
		    			break;
		    		}
		    	}
		    	else{
		    		break;
		    	}
		    }
    	}
    }

    cout << ans;
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
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