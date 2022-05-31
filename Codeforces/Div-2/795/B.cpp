#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

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
	for(int i = 1; i <= N; i++){
		cin >> A[i];
	}

	map<int, int> cnt;
	for(int i = 1; i <= N; i++){
		cnt[A[i]] += 1;
	}

	for(auto i : cnt){
		if(i.second == 1){
			cout << -1 << '\n';
			return;
		}
	}

	int i = 1;
	while(i <= N){
		vector<int> ansPermutation;
		for(int j = i + cnt[A[i]] - 1; j >= i; j--) ansPermutation.push_back(j);
		if(cnt[A[i]] & 1) swap(ansPermutation[cnt[A[i]] / 2], ansPermutation[cnt[A[i]] / 2 + 1]);
		for(int ans : ansPermutation) cout << ans << ' ';
		i += cnt[A[i]];
	}

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