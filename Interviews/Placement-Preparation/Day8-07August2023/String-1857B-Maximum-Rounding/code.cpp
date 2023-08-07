#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	string s; cin >> s;
	string answer = "";
	int i = s.size() - 1, k = s.size() - 1;
	while (i >= 0) {
		if (s[i] >= '5') {
			int j = i - 1;
			while (j >= 0 and s[j] == '9') {
				j--;
			}

			if (j >= 0) {
				while (k > j) s[k--] = '0';
				s[j] = s[j] + 1;
				i = j;
			} else {
				while (k >= 0) s[k--] = '0';
				cout << '1' << s << '\n';
				return;
			}
		} else {
			i--;
		}
	}

	cout << s << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}