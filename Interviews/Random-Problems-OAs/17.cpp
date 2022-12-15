#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int calculate_trip_cost(int mileage, int fuel_price) {
	int ans = ((500 + mileage - 1) / mileage) * fuel_price;
	return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m, fp; cin >> m >> fp;
	cout << calculate_trip_cost(m, fp);
	return 0;
}