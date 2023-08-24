#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include </home/archishman/DSA/DSA-Contests/archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> answer;
	for (int i = 0; i < n - 1; i++) {
		answer.push_back(a[i]);
		if (a[i] > a[i + 1]) answer.push_back(a[i + 1]);
	}

	answer.push_back(a[n - 1]);
	cout << answer.size() << '\n';
	for (int i = 0; i < answer.size(); i++) cout << answer[i] << " \n"[i == answer.size() - 1];
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}