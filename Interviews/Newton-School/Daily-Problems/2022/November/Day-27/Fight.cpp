#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int h, n, a;
	cin >> h >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		sum += a;
	}

	cout << (sum >= h ? "Yes" : "No");
	return 0;
}