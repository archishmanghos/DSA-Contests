#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <D:/archishmanghos/Practice/Online_Judges/archiDebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e4 + 5;
const int INF = 1e18 + 7;

int N, X, cache[105][mxN];
vector<pair<int, int>> A(mxN);

bool dp(int index, int dist){
	if(dist == X and index > N){
		return true;
	}

	if(index > N or dist > X){
		return false;
	}

	if(cache[index][dist] != -1){
		return cache[index][dist];
	}

	bool ans = false;
	if(dp(index + 1, dist + A[index].first) or dp(index + 1, dist + A[index].second)){
		ans = true;
	}

	return cache[index][dist] = ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N >> X;
	for(int i = 1; i <= N; i++) {
		cin >> A[i].first >> A[i].second;
	}

	memset(cache, -1, sizeof(cache));
	if(dp(1, 0)){
		cout << "Yes";
	}else{
		cout << "No";
	}

    return 0;
}