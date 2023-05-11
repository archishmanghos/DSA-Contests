#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int N; cin >> N;
	int A[N]; for (int i = 0; i < N; i++) cin >> A[i];

	int neg = 0;
	for (int i : A) neg += (i == -1);

	int negSub = 0;
	for (int i = 0; i < N; i++) {
		negSub += neg;
		neg -= (A[i] == -1);
	}

	int posSub = N * (N + 1) / 2 - negSub;
	cout << abs(negSub - posSub) << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}