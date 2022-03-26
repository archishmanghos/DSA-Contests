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

int N, K, A[mxN], B[mxN];
int cache[mxN][2];

bool dp(int index,bool arr){
	if(index == N){
		return true;
	}
	if(cache[index][arr] != -1){
		return cache[index][arr];
	}

	bool ans = false;
	if(arr){
		if(abs(A[index] - A[index + 1]) <= K){
			ans |= dp(index + 1, 1);
		}
		if(abs(A[index] - B[index + 1]) <= K){
			ans |= dp(index + 1, 0);
		}
	}else{
		if(abs(B[index] - A[index + 1]) <= K){
			ans |= dp(index + 1, 1);
		}
		if(abs(B[index] - B[index + 1]) <= K){
			ans |= dp(index + 1, 0);
		}
	}

	return cache[index][arr] = ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N >> K;
	for(int i = 1; i <= N; i++){
		cin >> A[i];
	}
	for(int i = 1; i <= N; i++){
		cin >> B[i];
	}

	memset(cache, -1, sizeof(cache));
	bool ans1 = dp(1, 1);
	bool ans2 = dp(1, 0);
	cout << (ans1 or ans2 ? "Yes" : "No");

    return 0;
}