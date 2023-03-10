#include <bits/stdc++.h>
#define int long long

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::queue<std::vector<int>> q;
	int frontRemoved = 0;

	int Q; std::cin >> Q;
	while (Q--) {
		int type; std::cin >> type;
		if (type == 1) {
			int X, C; std::cin >> X >> C;
			q.push({X, C});
		} else {
			int C; std::cin >> C;
			int answer = 0;
			while (C) {
				auto it = q.front();
				int add = std::min(it[1] - frontRemoved, C);
				answer += add * it[0];
				frontRemoved += add;
				C -= add;
				if (it[1] == frontRemoved) {
					q.pop();
					frontRemoved = 0;
				}
			}

			std::cout << answer << '\n';
		}
	}
	return 0;
}