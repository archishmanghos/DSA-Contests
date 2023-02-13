#include <bits/stdc++.h>
#define int long long
using namespace std;

int N, A[200200];

void solve() {
	cin >> N;
	set<int> s;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		s.insert(A[i]);
	}

	int i = 1, j = N;
	while (i < j) {
		int minn = *s.begin(), maxx = *s.rbegin();
		if (A[i] == minn or A[i] == maxx) {
			s.erase(A[i]);
			i++;
			continue;
		}
		if (A[j] == minn or A[j] == maxx) {
			s.erase(A[j]);
			j--;
			continue;
		}

		cout << i << ' ' << j << '\n';
		return;
	}

	cout << -1 << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}