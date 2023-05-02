#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, X, Y; cin >> N >> X >> Y;
	if (X > Y) swap(X, Y);
	int low = X, high = N * Y, answer = -1;

	while (low <= high) {
		int mid = low + (high - low) / 2;
		auto f = [&]() {
			int time = mid - X;
			int copies = (time / X) + (time / Y);
			return copies >= N - 1;
		};

		if (f()) {
			answer = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	cout << answer;
	return 0;
}