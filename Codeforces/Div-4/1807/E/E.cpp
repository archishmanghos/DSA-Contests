#include <bits/stdc++.h>
#define int long long

void solve() {
	int N; std::cin >> N;
	int A[N]; for (int i = 0; i < N; i++) std::cin >> A[i];
	int pref[N];
	pref[0] = A[0];
	for (int i = 1; i < N; i++) pref[i] = pref[i - 1] + A[i];

	int answer = -1, low = 1, high = N;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		std::cout << '?' << ' ' << mid << ' ';
		for (int i = 0; i < mid; i++) std::cout << (i + 1) << ' ';
		std::cout << endl;
		int actualWeight;
		std::cin >> actualWeight;
		int shouldBeWeight = pref[mid - 1];
		if (actualWeight > shouldBeWeight) {
			answer = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	std::cout << "! " << answer << endl;
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}