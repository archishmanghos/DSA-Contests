#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include </home/archishman/DSA/DSA-Contests/archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	string s; cin >> s;
	vector<char> unique;

	string decrypted = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' and s[i] <= '9') {
			if (unique.size() > (s[i] - '0')) {
				decrypted += unique[s[i] - '0'];
			} else {
				cout << "invalid code";
				return 0;
			}
		} else {
			decrypted += s[i];
			unique.push_back(s[i]);
		}
	}

	cout << decrypted;
	return 0;
}