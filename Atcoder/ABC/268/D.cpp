#include <bits/stdc++.h>
#define int long long
using namespace std;

bool possible(string password, int index, int underScore, int n, map<string, bool> &mp, vector<string> &S, string &ans) {
	if (index == n) {
		if (password.size() >= 3 and mp.find(password) == mp.end()) {
			ans = password;
			return true;
		}
		return false;
	}

	password += S[index];
	if (index == n - 1) {
		if (possible(password, index + 1, 0, n, mp, S, ans)) return true;
		return false;
	}

	int underScoreCanUse = underScore - (n - index - 2);
	for (int i = 1; i <= underScoreCanUse; i++) {
		password += '_';
		if (possible(password, index + 1, underScore - i, n, mp, S, ans)) return true;
	}

	return false;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M; cin >> N >> M;
	vector<string> S(N), T(M);
	int totSize = N - 1;
	for (int i = 0; i < N; i++) {
		cin >> S[i];
		totSize += 1LL * S[i].size();
	}

	map<string, bool> mp;
	for (int i = 0; i < M; i++) {
		cin >> T[i];
		mp[T[i]] = true;
	}

	if (totSize > 16) {
		cout << -1;
		return 0;
	}

	int maxUnderScoreCanBeUsed = 16 - (totSize - N + 1);
	sort(S.begin(), S.end());
	do {
		string ans = "";
		if (possible("", 0, maxUnderScoreCanBeUsed, N, mp, S, ans)) {
			cout << ans;
			return 0;
		}
	} while (next_permutation(S.begin(), S.end()));

	cout << -1;
	return 0;
}