#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {
	int N, W, H; cin >> N >> W >> H;
	int A[N + 2], B[N + 2];
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) cin >> B[i];

	auto check = [&](int centre) {
		int shift = B[1] - centre;
		int dir = 0;
		for (int i = 1; i <= N; i++) {
			int newPos = B[i] - shift;
			int l = newPos - H, r = newPos + H;
			if (l >= (A[i] - W) and r <= (A[i] + W)) continue;
			if (l < (A[i] - W) and r > (A[i] + W)) return -2ll;
			if (l < (A[i] - W)) {
				if (dir == -1) return -2ll;
				dir = 1;
			}
			if (r > (A[i] + W)) {
				if (dir == 1) return -2ll;
				dir = -1;
			}
		}
		return dir;
	};

	int low = A[1] - W + H, high = A[1] + W - H, answer = 0;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		int dir = check(mid);
		if (dir == 0) {
			answer = 1;
			break;
		}
		if (dir == -2) break;
		if (dir == -1) high = mid - 1;
		else low = mid + 1;
	}

	cout << (answer ? "YES" : "NO") << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}