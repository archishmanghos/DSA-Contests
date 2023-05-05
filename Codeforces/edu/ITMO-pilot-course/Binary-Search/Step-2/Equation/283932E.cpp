#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	double C; cin >> C;
	double answer = -1e7, low = 0, high = 1e7;
	while (high - low > 1e-6) {
		double mid = low + (high - low) / 2;
		auto f = [&]() {
			double ans = mid * mid + sqrt(mid);
			return ans;
		};

		double ans = f();
		if (abs(answer - C) > abs(ans - C)) answer = mid;
		if (ans > C) high = mid;
		else low = mid;
	}

	cout << fixed << setprecision(9) << answer;
	return 0;
}