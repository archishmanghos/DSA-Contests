#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M; cin >> N >> M;
	int F[M]; for (int i = 0; i < M; i++) cin >> F[i];
	sort(F, F + M);

	int diff = F[N - 1] - F[0], i = N;
	while (i < M) {
		diff = min(diff, F[i] - F[i - N + 1]);
		i++;
	}

	cout << diff;
	return 0;
}