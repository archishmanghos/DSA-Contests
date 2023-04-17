#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	string S; cin >> S;
	int count = 1;
	for (int i = 1; i < S.size(); i++) {
		if (S[i] == S[i - 1]) count++;
		else {
			if (count >= 7) {
				cout << "YES";
				return 0;
			}
			count = 1;
		}
	}

	cout << (count < 7 ? "NO" : "YES");
	return 0;
}