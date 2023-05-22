#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	int A[N];
	vector<int> odd;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (A[i] & 1) odd.push_back(A[i]);
	}

	sort(odd.begin(), odd.end());

	auto lb = [&](int val) {
		int answer = -1, low = 0, high = odd.size() - 1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (odd[mid] >= val) {
				answer = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}

		return (answer == -1 ? odd.size() : answer);
	};

	// all even
	bool ok = true;
	for (int i = 0; i < N; i++) {
		if (A[i] & 1) {
			int idx = lb(A[i]);
			if (idx == 0 or odd[idx - 1] > A[i]) {
				ok = false;
				break;
			}
		}
	}

	if (ok) {
		cout << "YES" << '\n';
		return;
	}

	// all odd
	ok = true;
	for (int i = 0; i < N; i++) {
		if (!(A[i] & 1)) {
			int idx = lb(A[i]);
			if (idx == 0) {
				ok = false;
				break;
			}
		}
	}

	cout << (ok ? "YES" : "NO") << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}