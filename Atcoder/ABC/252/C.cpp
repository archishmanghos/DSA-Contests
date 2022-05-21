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

int N;
string S[mxN];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N;
	for(int i = 1; i <= N; i++) cin >> S[i];

	vector<vector<int>> dist(N + 2, vector<int>(10, 0));
	for(int i = 1; i <= N; i++){
		for(int j = 0; j < 10; j++) dist[i][S[i][j] - '0'] = j;
	}
	
	int ans = INF;
	for(int i = 0; i < 10; i++){
		int minn = 0;
		vector<int> times, finalTimes;
		for(int j = 1; j <= N; j++) times.push_back(dist[j][i]);
		sort(times.begin(), times.end());
		finalTimes = times;
		for(int i = 1; i < N; i++){
			if(times[i] == times[i - 1]) finalTimes[i] = finalTimes[i - 1] + 10;
			minn = max(minn, finalTimes[i]);
		}

		ans = min(ans, minn);
	}

	cout << ans << '\n';

    return 0;
}