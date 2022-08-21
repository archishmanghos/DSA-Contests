#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

string findSmallestUnit(string str) {
	vector<int> lps(str.length(), 0);
	int i = 1;
	int len = 0;

	while (i < str.length()) {
		if (str[i] == str[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else {
			if (len == 0) i++;
			else {
				len = lps[len - 1];
			}
		}
	}
	int n = str.length();
	int x = lps[n - 1];
	if (n % (n - x) == 0) {
		return str.substr(0, n - x);
	}
	return str;
}

// https://stackoverflow.com/a/65515273

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	cout << findSmallestUnit(s) << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}