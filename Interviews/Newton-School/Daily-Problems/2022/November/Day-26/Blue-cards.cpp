#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int64_t n, a, b; cin >> n >> a >> b;
	int64_t totGroups = n / (a + b);
	int64_t remCards = min(a, n % (a + b));
	cout << (totGroups * a + remCards);
	return 0;
}