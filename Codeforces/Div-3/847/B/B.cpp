#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {
	int N, R, S; cin >> N >> S >> R;
	vector<int> answer;
	answer.push_back(S - R);
	S -= (S - R);
	for (int i = 1; i < N; i++) answer.push_back(1);
	S -= N - 1;

	if (S) {
		for (int i = 1; i < N; i++) {
			int add = min(min(5ll, S), answer[0] - 1);
			answer[i] += add;
			S -= add;
			if (S == 0) break;
		}
	}

	for (int i = 0; i < N; i++) cout << answer[i] << ' ';
	cout << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}