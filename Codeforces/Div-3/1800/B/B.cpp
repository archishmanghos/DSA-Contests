#include <bits/stdc++.h>
#define int long long
using namespace std;

int N, K;
string S;

void solve() {
	cin >> N >> K >> S;
	vector<int> cntLower(26, 0), cntUpper(26, 0);
	for (int i = 0; i < N; i++) {
		if (S[i] >= 'A' and S[i] <= 'Z') cntUpper[S[i] - 'A'] += 1;
		else cntLower[S[i] - 'a'] += 1;
	}

	int answer = 0;
	for (int i = 0; i < 26; i++) {
		answer += min(cntLower[i], cntUpper[i]);
		int extra = abs(cntLower[i] - cntUpper[i]) / 2;
		int x = min(K, extra);
		answer += x;
		K -= x;
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