#include <bits/stdc++.h>
#define int long long
using namespace std;

int N;
string S;

void solve() {
	cin >> N >> S;
	int count = 0, answer = N - 1;
	for (int i = 2; i < N; i += 2) count += S[i] == S[i - 2];
	for (int i = 3; i < N; i += 2) count += S[i] == S[i - 2];

	cout << (answer - count) << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}