#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	string S; cin >> S;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '0') {
			cout << S.substr(0, i) << (i + 1 < S.size() ? S.substr(i + 1) : "");
			return 0;
		}
	}

	cout << S.substr(1);
	return 0;
}