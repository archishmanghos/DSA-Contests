#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int N; cin >> N;
	map<int, int> mp;
	int A[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		mp[A[i]]++;
	}

	int answer = 0, maxx = *max_element(A, A + N);
	for (int i = 0; i < N; i++) {
		if (mp[A[i]] > 2) answer += (mp[A[i]] - 1) * (mp[A[i]] - 2);
	}

	for (auto it : mp) {
		int x = it.first;
		for (int i = 2; x * i * i <= maxx; i++) {
			if (mp.find(x * i) != mp.end() and mp.find(x * i * i) != mp.end()) answer += it.second * mp[x * i] * mp[x * i * i];
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