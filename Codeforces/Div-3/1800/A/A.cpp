#include <bits/stdc++.h>
#define int long long
using namespace std;

int N;
string S;

void solve() {
	cin >> N >> S;
	string T = "meow";
	int j = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] >= 'A' and S[i] <= 'Z') S[i] = tolower(S[i]);
		if (S[i] == T[j]) continue;
		j++;
		if (j > 3 or S[i] != T[j]) {
			cout << "NO" << '\n';
			return;
		}
	}

	cout << (j == 3 ? "YES" : "NO") << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}