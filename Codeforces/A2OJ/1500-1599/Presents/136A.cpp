#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N; cin >> N;
	int answer[N];
	for (int i = 0; i < N; i++) {
		int A; cin >> A;
		answer[A - 1] = (i + 1);
	}

	for (int i = 0; i < N; i++) cout << answer[i] << ' ';
	return 0;
}