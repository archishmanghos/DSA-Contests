#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int minimumFlips(string &target) {
	int n = target.size(), pos = -1, ans = 1;
	for (int i = 0; i < n; i++) {
		if (target[i] == '1') {
			pos = i;
			break;
		}
	}

	if (pos == -1) {
		return 0;
	}

	for (int i = pos + 1; i < n; i++) {
		if (target[i] != target[i - 1]) {
			ans += 1;
		}
	}

	return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s; cin >> s;
	cout << minimumFlips(s);
	return 0;
}