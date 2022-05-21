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

int N, K, A[mxN], B;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N >> K;
	int maxx = 0;
	set<int> maxPos;
	for(int i = 1; i <= N; i++){
		cin >> A[i];
		maxx = max(maxx, A[i]);
	}

	for(int i = 1; i <= N; i++){
		if(maxx == A[i]) maxPos.insert(i);
	}

	bool ans = false;
	for(int i = 1; i <= N; i++){
		cin >> B;
		if(maxPos.find(B) != maxPos.end()){
			ans = true;
		}
	}

	cout << (ans ? "Yes" : "No") << '\n';

    return 0;
}