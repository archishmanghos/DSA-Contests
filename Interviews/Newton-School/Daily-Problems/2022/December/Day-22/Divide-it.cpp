#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int index[13];
	for (int i = 1; i <= 12; i++) {
		if ((i < 8 and (i & 1)) or (i >= 8 and !(i & 1))) index[i] = 1;
		else index[i] = 2;
	}

	index[2] = 3;

	int x, y; cin >> x >> y;
	cout << (index[x] == index[y] ? "Yes" : "No");
	return 0;
}