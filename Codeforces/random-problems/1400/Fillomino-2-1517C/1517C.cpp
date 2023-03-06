#include <bits/stdc++.h>
#define i64 int64_t
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N; std::cin >> N;
	int A[N + 2]; for (int i = 1; i <= N; i++) std::cin >> A[i];

	std::vector<std::vector<int>> v(N + 2, std::vector<int> (N + 2, -1));
	for (int i = 1; i <= N; i++) {
		int start = A[i], j = i, k = i;
		while (start) {
			if (k < 1 or v[j][k] != -1) j++, k++;
			if (j > N) {
				std::cout << -1;
				return 0;
			}

			v[j][k] = A[i];
			start--, k--;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) std::cout << v[i][j] << ' ';
		std::cout << '\n';
	}
	return 0;
}