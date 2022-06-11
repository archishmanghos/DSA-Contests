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

int T, N, A[mxN];

void solve() {
    cin >> N;
    for(int i = 1; i <= N; i++) {
    	cin >> A[i];
    }

    if(N & 1){
    	cout << "NO" << '\n';
    	return;
    }

    sort(A + 1, A + N + 1);
    vector<int> A1, A2, ans;
    for(int i = 1; i <= N / 2; i++) A1.push_back(A[i]);
    for(int i = N / 2 + 1; i <= N; i++) A2.push_back(A[i]);

    int i = 0, j = 0;
	while(i < N / 2){
		ans.push_back(A1[i++]);
		ans.push_back(A2[j++]);
	}

	for(int i = 0; i < N; i++){
		int leftNeighbour = (i == 0 ? ans[N - 1] : ans[i - 1]);
		int rightNeighbour = (i == N - 1 ? ans[0] : ans[i + 1]);
		if(ans[i] > leftNeighbour and ans[i] > rightNeighbour) continue;
		if(ans[i] < leftNeighbour and ans[i] < rightNeighbour) continue;
		cout << "NO" << '\n';
		return;
	}

	cout << "YES" << '\n';
	for(int i : ans) cout << i << ' ';
	cout << '\n';
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