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
	int cnt[2] = {0};
	for(int i = 1; i <= 2 * N; i++){
		cin >> A[i];
		cnt[A[i] % 2] += 1;
	}

	if(cnt[1] == cnt[0]) cout << 0 << '\n';
	else if(cnt[1] > cnt[0]) cout << (cnt[1] - cnt[0]) / 2 << '\n';
	else{
		vector<int> evens;
		for(int i = 1; i <= 2 * N; i++){
			if(A[i] % 2 == 0){
				int cntSteps = 0;
				while(A[i] % 2 == 0) cntSteps += 1, A[i] >>= 1;
				evens.push_back(cntSteps);
			}
		}

		sort(evens.begin(), evens.end());
		int reqd = (cnt[0] - cnt[1]) / 2;
		int ans = 0;
		for(int i = 0; i < reqd; i++) ans += evens[i];
		cout << ans << '\n';
	}
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
        solve();

    return 0;
}