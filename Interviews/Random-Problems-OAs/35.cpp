#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include </home/archishman/DSA/DSA-Contests/archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N; cin >> N;
	int R[N + 1], C[N + 1];
	for (int i = 0; i <= N; i++) cin >> R[i];
	for (int i = 0; i <= N; i++) cin >> C[i];

	int cache[N + 1];
	for (int i = 0; i <= N; i++) cache[i] = 1e9;
	cache[0] = 0;
	for (int i = 0; i <= N; i++) {
		int start = max(0ll, i - R[i]);
		int end = min(N, i + R[i]);
		for (int j = start; j <= end; j++) cache[j] = min(cache[j], cache[start] + C[i]);
	}

	cout << (cache[N - 1] == 1e9 ? -1 : cache[N - 1]);
	return 0;
}