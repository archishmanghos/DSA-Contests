#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, K; cin >> N >> K;
	for (int i = K + 1; i <= N; i++) cout << i << ' ';
	for (int i = K; i >= 1; i--) cout << i << ' ';
	return 0;
}