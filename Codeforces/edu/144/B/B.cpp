#include <bits/stdc++.h>
#define int long long
using namespace std;

string A, B;

void solve() {
	cin >> A >> B;
	if (A[0] == B[0] or A.back() == B.back()) {
		cout << "YES" << '\n';
		if (A[0] == B[0]) cout << A[0] << '*' << '\n';
		else cout << '*' << A.back() << '\n';
		return;
	}

	map<string, int> mp;
	for (int i = 0; i < B.size() - 1; i++) {
		string x = B.substr(i, 2);
		mp[x] = 1;
	}
	for (int i = 0; i < A.size() - 1; i++) {
		string x = A.substr(i, 2);
		if (mp.find(x) != mp.end()) {
			cout << "YES" << '\n';
			cout << '*' << x << '*' << '\n';
			return;
		}
	}

	cout << "NO" << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}