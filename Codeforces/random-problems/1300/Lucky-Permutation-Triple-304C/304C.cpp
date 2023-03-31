#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N; cin >> N;
	if (N & 1) {
		for (int i = 0; i < N; i++) cout << i << " \n"[i == N - 1];
		for (int i = 0; i < N; i++) cout << i << " \n"[i == N - 1];
		for (int i = 0; i < N; i++) cout << (2 * i) % N << ' ';
	} else {
		cout << -1;
	}
	return 0;
}