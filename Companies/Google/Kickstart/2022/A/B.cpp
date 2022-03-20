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

void solve()
{
	cin >> S;
	int sum = 0;
	for(char c : S){
		sum += (c - '0');
	}

	int toAdd = sum % 9;
	if(toAdd == 0){
		string ans = "";
		ans += S[0];
		ans += '0';
		ans += S.substr(1);
		cout << ans << '\n';
		return;
	}
	toAdd = 9 - toAdd;
	
	for(int i = 0; i < S.size(); i++){
		if(toAdd < (S[i] - '0')){
			string left = S.substr(0, i);
			string right = S.substr(i);
			string ans = left;
			ans += (toAdd + '0');
			ans += right;
			cout << ans << '\n';
			return;
		}
	}
	
	S += (toAdd + '0');
	cout << S << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}