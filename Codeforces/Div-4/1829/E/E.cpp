#include <bits/stdc++.h>
using namespace std;

int N, M, A[1005][1005];

void dfs(int r, int c, int &sum) {
	sum += A[r][c];
	A[r][c] = 0;
	if (r + 1 < N and A[r + 1][c]) dfs(r + 1, c, sum);
	if (r - 1 >= 0 and A[r - 1][c]) dfs(r - 1, c, sum);
	if (c + 1 < M and A[r][c + 1]) dfs(r, c + 1, sum);
	if (c - 1 >= 0 and A[r][c - 1]) dfs(r, c - 1, sum);
}

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j]) {
				int sum = 0;
				dfs(i, j, sum);
				answer = max(answer, sum);
			}
		}
	}

	cout << answer << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}