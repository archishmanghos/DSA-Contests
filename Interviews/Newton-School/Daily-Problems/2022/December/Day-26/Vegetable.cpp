#include <bits/stdc++.h>
using namespace std;

int cache[105][105];

int dp(int dish, int veg) {
	if (dish == 0) return veg == 0;

	int &ans = cache[dish][veg];
	if (ans != -1) return ans;

	ans = dp(dish - 1, veg - 2) | dp(dish - 1, veg - 4);
	return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int dish, veg; cin >> dish >> veg;
	memset(cache, -1, sizeof(cache));

	cout << (dp(dish, veg) ? "Yes" : "No");
	return 0;
}