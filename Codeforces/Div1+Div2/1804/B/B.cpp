#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {
	int N, K, D, W; cin >> N >> K >> D >> W;
	int A[N]; for (int i = 0; i < N; i++) cin >> A[i];

	int answer = 0, i = 0, j = 0;
	while (j < N) {
		int patients = 0;
		while (j < N and (j - i + 1) <= K and A[j] - A[i] <= (D + W)) j++;
		i = j;
		answer++;
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