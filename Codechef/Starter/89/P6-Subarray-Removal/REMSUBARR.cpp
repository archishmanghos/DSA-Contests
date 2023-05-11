#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	int A[N], i = -1, j = -1;
	for (int k = 0; k < N; k++) {
		cin >> A[k];
		if (A[k] == N) i = j = k;
	}

	set<int> s;
	s.insert(A[i]);
	int answer = 0;
	while (s.size() < N) {
		int minn = *s.begin(), maxx = *s.rbegin();
		if (maxx - minn + 1 == s.size()) answer = max(answer, (int)s.size());
		if (i - 1 >= 0 and j + 1 < N) {
			if (A[i - 1] > A[j + 1]) s.insert(A[--i]);
			else s.insert(A[++j]);
		} else if (i - 1 >= 0) {
			s.insert(A[--i]);
		} else {
			s.insert(A[++j]);
		}
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