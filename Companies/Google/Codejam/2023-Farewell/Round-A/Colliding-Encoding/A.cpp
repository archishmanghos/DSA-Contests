#include <bits/stdc++.h>
using namespace std;

void solve() {
	int mapp[26];
	for (int i = 0; i < 26; i++) {
		cin >> mapp[i];
	}

	int N; cin >> N;
	map<string, string> mp;
	for (int i = 0; i < N; i++) {
		string S; cin >> S;
		string encode = "";
		for (char c : S) {
			encode += (mapp[c - 'A'] + '0');
		}

		if (mp.find(S) == mp.end()) mp[S] = encode;
	}

	set<string> s;
	for (auto it : mp) {
		s.insert(it.second);
	}

	cout << (s.size() == mp.size() ? "NO" : "YES") << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}