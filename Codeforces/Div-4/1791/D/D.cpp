#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {
	int N; cin >> N;
	string S; cin >> S;

	vector<int> cnt(26, 0), pref(N, 0), suff(N, 0);
	for (int i = 0; i < N; i++) {
		if (cnt[S[i] - 'a'] == 0) pref[i] = 1;
		cnt[S[i] - 'a'] += 1;
		if (i > 0) pref[i] += pref[i - 1];
	}

	cnt.assign(26, 0);
	for (int i = N - 1; i >= 0; i--) {
		if (cnt[S[i] - 'a'] == 0) suff[i] = 1;
		cnt[S[i] - 'a'] += 1;
		if (i < N - 1) suff[i] += suff[i + 1];
	}

	int answer = suff[0];
	for (int i = 0; i < N - 1; i++) answer = max(answer, pref[i] + suff[i + 1]);

	cout << answer << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}