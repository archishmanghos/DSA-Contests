#include <bits/stdc++.h>
using namespace std;

int N, M, visited[50][50];
string S[50];

bool isCycle(int r, int c, int preDir) {
	if (visited[r][c]) return true;

	visited[r][c] = 1;
	int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
	for (int i = 0; i < 4; i++) {
		if ((r + dx[i]) < 0 or (r + dx[i]) >= N or (c + dy[i]) < 0 or (c + dy[i]) >= M or S[r + dx[i]][c + dy[i]] != S[r][c]) continue;
		if (i != preDir) {
			if (isCycle(r + dx[i], c + dy[i], (i + 2) % 4)) return true;
		}
	}

	return false;
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> S[i];

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if ((S[j][k] - 'A') == i and !visited[j][k]) {
					if (isCycle(j, k, -1)) {
						cout << "Yes";
						return 0;
					}
				}
			}
		}
	}

	cout << "No";
	return 0;
}