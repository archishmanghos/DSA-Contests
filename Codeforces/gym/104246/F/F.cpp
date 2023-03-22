#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int N, M; cin >> N >> M;
	map<int, int> mp;
	int A[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		mp[A[i]]++;
	}

	int answer = mp.size();
	while (M--) {
		int P, X; cin >> P >> X;
		P--;
		int oldPoint = A[P];
		A[P] += X;
		mp[oldPoint]--;
		if (!mp[oldPoint]) answer--;
		mp[A[P]]++;
		if (mp[A[P]] == 1) answer++;
		cout << answer << '\n';
	}
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}