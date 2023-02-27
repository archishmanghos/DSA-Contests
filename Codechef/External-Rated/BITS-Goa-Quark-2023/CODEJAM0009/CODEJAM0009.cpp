#include <bits/stdc++.h>
#define int long long
using namespace std;

int N;
string S;

void solve() {
	cin >> N >> S;
	int answer = 1e9;
	for (char c = 'a'; c <= 'z'; c++) {
		int steps = 0;
		for (int i = 0; i < N; i++) {
			char a = c, b = S[i];
			if (a > b) swap(a, b);
			steps += (b - a);
		}

		answer = min(answer, steps);
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