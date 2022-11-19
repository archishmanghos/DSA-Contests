#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string names[3];
	for (int i = 0; i < 3; i++) {
		cin >> names[i];
	}
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int canPlant[3] = {7, 3, 1};
	for (int i = 0; i < n; i++) {
		int curPlayer = -1;
		for (int j = 0; j < 3; j++) {
			int turns = a[i] / canPlant[j];
			curPlayer = (curPlayer + turns) % 3;
			a[i] %= canPlant[j];
		}
		cout << names[curPlayer] << ' ';
	}
	return 0;
}