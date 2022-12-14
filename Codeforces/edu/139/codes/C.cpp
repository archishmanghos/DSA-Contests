#include <bits/stdc++.h>
const int mxn = 2e5 + 5;

char grid[2][mxn];

bool possible(std::vector<int> start, std::vector<int> end, int n) {
	std::queue<std::vector<int>> q;
	q.push(start);

	while (!q.empty()) {
		int r = q.front()[0], c = q.front()[1], rpar = q.front()[2], cpar = q.front()[3];
		q.pop();

		if (r == end[0] and c == end[1]) {
			return true;
		}

		std::vector<int> temp = {r, c, rpar, cpar};

		if (r == 0) {
			bool right = (c + 1 < n and grid[r][c + 1] == 'B'), down = (r + 1 < 2 and grid[r + 1][c] == 'B');
			if (rpar == r and cpar == (c + 1)) {
				right = false;
			}
			if (rpar == (r + 1) and cpar == c) {
				down = false;
			}

			if (down) {
				q.push({r + 1, c, r, c});
			} else if (right) {
				q.push({r, c + 1, r, c});
			} else {
				return false;
			}
		} else {
			bool right = (c + 1 < n and grid[r][c + 1] == 'B'), up = (r - 1 >= 0 and grid[r - 1][c] == 'B');
			if (rpar == r and cpar == (c + 1)) {
				right = false;
			}
			if (rpar == (r - 1) and cpar == c) {
				up = false;
			}
			if (up) {
				q.push({r - 1, c, r, c});
			} else if (right) {
				q.push({r, c + 1, r, c});
			} else {
				return false;
			}
		}
	}

	return false;
}

void solve() {
	int n; std::cin >> n;
	int lastCol = 0, firstCol = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> grid[i][j];
			if (grid[i][j] == 'B') {
				firstCol = std::min(firstCol, j);
				lastCol = std::max(lastCol, j);
			}
		}
	}

	std::vector<int> start1 = { -1}, start2 = { -1}, end1 = { -1}, end2 = { -1};
	if (grid[0][lastCol] == 'B') {
		end1 = {0, lastCol};
	}
	if (grid[1][lastCol] == 'B') {
		end2 = {1, lastCol};
	}


	if (grid[0][firstCol] == 'B') {
		start1 = {0, firstCol, -1, -1};
	}
	if (grid[1][firstCol] == 'B') {
		start2 = {1, firstCol, -1, -1};
	}

	if (start1[0] != -1) {
		if (end1[0] != -1) {
			if (possible(start1, end1, n)) {
				std::cout << "YES" << '\n';
				return;
			}
		}
		if (end2[0] != -1) {
			if (possible(start1, end2, n)) {
				std::cout << "YES" << '\n';
				return;
			}
		}
	}
	if (start2[0] != -1) {
		if (end1[0] != -1) {
			if (possible(start2, end1, n)) {
				std::cout << "YES" << '\n';
				return;
			}
		}
		if (end2[0] != -1) {
			if (possible(start2, end2, n)) {
				std::cout << "YES" << '\n';
				return;
			}
		}
	}

	std::cout << "NO" << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}