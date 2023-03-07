#include <bits/stdc++.h>
#define i64 int64_t

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, Q; std::cin >> N >> Q;
	std::map<int, std::vector<int>> mp;
	int A[N + 2]; for (int i = 1; i <= N; i++) {
		std::cin >> A[i];
		mp[A[i]].push_back(i);
	}

	while (Q--) {
		int X, K; std::cin >> X >> K;
		if (mp.find(X) != mp.end() and mp[X].size() >= K) {
			std::cout << mp[X][K - 1] << '\n';
		} else {
			std::cout << -1 << '\n';
		}
	}

	return 0;
}