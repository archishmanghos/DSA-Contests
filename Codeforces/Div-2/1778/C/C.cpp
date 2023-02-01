#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {
	int N, K; cin >> N >> K;
	string A, B; cin >> A >> B;

	vector<char> toChange;
	vector<int> cnt(26, 0);
	for (int i = 0; i < N; i++) {
		if (A[i] != B[i]) {
			if (!cnt[A[i] - 'a']) {
				toChange.push_back(A[i]);
				cnt[A[i] - 'a'] += 1;
			}
		}
	}

	int n = toChange.size();
	if (n == 0) {
		cout << N * (N + 1) / 2 << '\n';
		return;
	}

	auto getPairs = [&](vector<bool> &cn) {
		int pairs = 0, cnt = 0;
		for (int i = 0; i < A.size(); i++) {
			if (A[i] == B[i] or cn[A[i] - 'a']) cnt += 1;
			else {
				pairs += cnt * (cnt + 1) / 2;
				cnt = 0;
			}
		}

		pairs += cnt * (cnt + 1) / 2;
		return pairs;
	};

	int answer = 0;
	for (int i = 0; i < (1 << n); i++) {
		vector<bool> changeNow(26, 0);
		int count = 0;
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				changeNow[toChange[j] - 'a'] = 1;
				count += 1;
			}
		}

		if (count <= K) answer = max(answer, getPairs(changeNow));
	}

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