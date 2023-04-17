#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	auto printSeries = [](int n) {
		for (int j = 0; j < n; j++) cout << j << ' ';
		for (int j = n; j >= 0; j--) cout << j << (j - 1 >= 0 ? " " : "");
		cout << '\n';
	};

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		for (int space = 1; space <= (N - i); space++) cout << "  ";
		printSeries(i);
	}

	printSeries(N);

	for (int i = N - 1; i >= 0; i--) {
		for (int space = 1; space <= (N - i); space++) cout << "  ";
		printSeries(i);
	}

	return 0;
}