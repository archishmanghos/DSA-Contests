#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; string S; cin >> N >> S;

	if (N & 1) {
		cout << -1 << '\n';
		return;
	}

	int cnt[26] = {0};
	for (char c : S) cnt[c - 'a']++;

	for (int i = 0; i < 26; i++) {
		if (cnt[i] > (N / 2)) {
			cout << -1 << '\n';
			return;
		}
	}

	memset(cnt, 0, sizeof(cnt));
	int i = 0, j = N - 1, equalPairs = 0;
	while (i < j) {
		if (S[i] == S[j]) {
			cnt[S[i] - 'a']++;
			equalPairs++;
		}
		i++, j--;
	}

	int answer = (equalPairs + 1) / 2;
	for (int i = 0; i < 26; i++) answer = max(answer, cnt[i]);
	cout << answer << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}