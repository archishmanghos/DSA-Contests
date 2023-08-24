#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n, m; cin >> n >> m;
	char a[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> a[i][j];
	}

	int k = 0;
	string str = "vika";


	for (int i = 0; i < m; i++) {
		if (k == 4) {
			cout << "YES" << '\n';
			return;
		}
		for (int j = 0; j < n; j++) {
			if (a[j][i] == str[k]) {
				k++;
				break;
			}
		}
	}

	cout << (k == 4 ? "YES" : "NO") << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}