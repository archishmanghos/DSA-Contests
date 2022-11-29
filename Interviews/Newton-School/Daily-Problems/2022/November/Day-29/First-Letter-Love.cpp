#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	string s, pre;
	set<string> st;

	for (int i = 1; i <= n; i++) {
		cin >> s;
		if (i != 1) {
			if (pre.back() != s[0] or st.find(s) != st.end()) {
				cout << "No";
				return 0;
			}
		}

		st.insert(s);
		pre = s;
	}

	cout << "Yes";
	return 0;
}