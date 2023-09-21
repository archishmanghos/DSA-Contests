#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include </home/archishman/DSA/DSA-Contests/archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {
	string s; cin >> s;
	int answer = 0;

	vector<int> a;
	int cntb = 0, cnta = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A') cnta++;
		else {
			if (cnta) a.push_back(cnta);
			cnta = 0;
			cntb++;
		}
	}
	if (cnta) a.push_back(cnta);

	sort(a.begin(), a.end(), greater<int>());
	for (int i = 0; i < min(cntb, (int)a.size()); i++) answer += a[i];

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