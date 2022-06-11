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
	for(int i = 1; i <= N; i++) cin >> A[i];
	set<int> s;
	for(int i = 1; i <= N; i++) s.insert(A[i]);

	if(N == 1) {
		cout << -1 << '\n';
		return;
	}

	vector<int> ans;
	for(int i = 1; i <= N; i++){
		auto it = s.begin();
		if(*it == A[i] and s.size() > 1) it++;
		int element = *it;
		ans.push_back(element);
		s.erase(element);
	}

	if(ans.back() == A[N]) swap(ans[N - 1], ans[N - 2]);
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