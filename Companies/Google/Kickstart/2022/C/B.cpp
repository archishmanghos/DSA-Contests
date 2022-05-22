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

int T, N, X, Y;

void solve() {
    cin >> N >> X >> Y;
    int sum = N * (N + 1) / 2;
    if(sum % (X + Y) == 0){
    	int alanScore = (sum / (X + Y)) * X;
    	cout << "POSSIBLE" << '\n';
    	if(alanScore <= N) {
    		cout << 1 << '\n' << alanScore << '\n';
    		return;
    	}
    	vector<int> ans;
		for(int i = N; i >= 1; i--){
			if(alanScore >= i) {
				alanScore -= i;
				ans.push_back(i);
			}
		}

		cout << ans.size() << '\n';
		for(int i : ans) cout << i << ' ';
		cout << '\n';

    }else cout << "IMPOSSIBLE" << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}