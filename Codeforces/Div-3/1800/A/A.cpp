#include <bits/stdc++.h>
#define int long long
using namespace std;

int N;
string S;

void solve() {
	cin >> N >> S;
	string T = "";
	for (int i = 0; i < N; i++) {
		char ch = char(S[i] | 1 << 5);
		if (T.size() == 0 or T.back() != ch) T += ch;
	}

	cout << (T == "meow" ? "YES" : "NO") << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}