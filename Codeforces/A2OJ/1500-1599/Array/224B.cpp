#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, K; cin >> N >> K;
	int A[N]; for (int i = 0; i < N; i++) cin >> A[i];

	set<int> s;
	map<int, int> mp;

	int i = 0, l = 0, r = 0;
	while (i < N and s.size() < K) {
		s.insert(A[i]);
		mp[A[i]]++;
		r = i;
		i++;
	}

	if (s.size() == K) {
		while (mp[A[l]] > 1) {
			mp[A[l]]--;
			l++;
		}

		cout << (l + 1) << ' ' << (r + 1) << '\n';
	}
	else cout << -1 << ' ' << -1;
	return 0;
}