#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

bool orderMaintained(vector<int> &A, vector<int> &B, int pos, int N) {
	for (int i = pos, j = 0; i < N; i++, j++) {
		if (A[i] != B[j]) {
			return false;
		}
	}

	for (int i = 0, j = N - pos; i < pos; i++, j++) {
		if (A[i] != B[j]) {
			return false;
		}
	}

	return true;
}

void solve() {
	int N, K; cin >> N >> K;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];

	int pos = -1;
	for (int i = 0; i < N; i++) {
		if (A[i] == B[0]) {
			pos = i;
			break;
		}
	}

	if (!orderMaintained(A, B, pos, N)) {
		cout << "NO" << '\n';
	} else {
		if (K == 0) {
			cout << (pos == 0 ? "YES" : "NO") << '\n';
		} else {
			if (N == 2) {
				if (pos == 0) {
					cout << (K % 2 == 0 ? "YES" : "NO") << '\n';
				} else {
					cout << (K % 2 == 1 ? "YES" : "NO") << '\n';
				}
			} else {
				if (pos == 0) {
					cout << (K > 1 ? "YES" : "NO") << '\n';
				} else {
					cout << "YES" << '\n';
				}
			}
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}