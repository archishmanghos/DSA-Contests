#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int N; cin >> N;
	int A[N], B[N];
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];

	int l, r;
	for (int i = 0; i < N; i++) {
		if (A[i] != B[i]) {
			l = i;
			break;
		}
	}

	for (int i = N - 1; i >= 0; i--) {
		if (A[i] != B[i]) {
			r = i;
			break;
		}
	}

	int minn = *min_element(A + l, A + r + 1);
	int maxx = *max_element(A + l, A + r + 1);

	while (l - 1 >= 0 and A[l - 1] <= minn) {
		l--;
		minn = A[l];
	}

	while (r + 1 < N and A[r + 1] >= maxx) {
		r++;
		maxx = A[r];
	}

	cout << (l + 1) << ' ' << (r + 1) << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}