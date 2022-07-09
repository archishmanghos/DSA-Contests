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

pair<int, int> launchTime, timeTaken;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> launchTime.first >> launchTime.second >> timeTaken.first >> timeTaken.second;

	pair<int,int> ans;
	if(launchTime.second + timeTaken.second >= 60){
		ans.first = (launchTime.first + timeTaken.first + 1) % 24;
		ans.second = (launchTime.second + timeTaken.second) % 60;
	}else{
		ans.first = (launchTime.first + timeTaken.first) % 24;
		ans.second = launchTime.second + timeTaken.second;
	}

	if(ans.first < 10){
		cout << '0';
	}
	cout << ans.first << ' ';
	if(ans.second < 10){
		cout << '0';
	}
	cout << ans.second;

    return 0;
}