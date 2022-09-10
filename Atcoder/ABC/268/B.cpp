#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string S, T; cin >> S >> T;
	if (S.size() > T.size()) {
		cout << "No";
		return 0;
	}

	int i = 0, j = 0;
	while (i < S.size()) {
		if (S[i++] != T[j++]) {
			cout << "No";
			return 0;
		}
	}

	cout << "Yes";
	return 0;
}