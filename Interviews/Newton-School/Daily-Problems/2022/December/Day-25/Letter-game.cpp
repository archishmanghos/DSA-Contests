#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s; cin >> s;
	sort(s.begin(), s.end());
	cout << (s[0] == s[2] ? "Won" : "Lost");
	return 0;
}