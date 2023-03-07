#include <bits/stdc++.h>
#define i64 int64_t

int N, S;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> N >> S;
	if (S < 1) {
		std::cout << (N > 1 ? "-1 -1" : "0 0");
		return 0;
	}

	std::vector<int> maximum(N, 0), minimum(N, 0);
	maximum[0] = minimum[0] = 1;
	int S1 = S - 1, S2 = S - 1;
	for (int i = 0; i < N; i++) {
		int x = std::min(S1, 9 - maximum[i]);
		maximum[i] += x;
		S1 -= x;

		x = std::min(S2, 9 - minimum[N - i - 1]);
		minimum[N - i - 1] += x;
		S2 -= x;
	}

	if (S1 or S2) {
		std::cout << "-1 -1";
		return 0;
	}

	for (int i : minimum) std::cout << i;
	std::cout << ' ';
	for (int i : maximum) std::cout << i;
	return 0;
}