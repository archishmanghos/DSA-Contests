#include <bits/stdc++.h>
using namespace std;

int32_t main() {

	int Y; cin >> Y;
	if (Y % 4 <= 2) cout << (Y + 2 - (Y % 4));
	else cout << Y + 3;

	return 0;
}