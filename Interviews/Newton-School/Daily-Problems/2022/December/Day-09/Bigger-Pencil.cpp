#include <bits/stdc++.h>
using namespace std;

int helper (int idx, std::vector<int> pencil, std::vector<int> &x, std::vector<int> &l, int n) {
	if (idx == n) {
		int diff = 0;
		for (int i = 0; i < 3; i++) {
			if (pencil[i] == -1) {
				return 1e9;
			}
			diff += abs(pencil[i] - x[i]);
		}
		return diff;
	}

	int ans = helper(idx + 1, pencil, x, l, n);
	for (int i = 0; i < 3; i++) {
		int pre = pencil[i];
		pencil[i] = (pre == -1 ? l[idx] : pre + l[idx]);
		ans = min(ans, helper(idx + 1, pencil, x, l, n) + (pre == -1 ? 0 : 10));
		pencil[i] = pre;
	}

	return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	std::vector<int> x(3); cin >> x[0] >> x[1] >> x[2];
	std::vector<int> l(n);
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}

	cout << helper(0, { -1, -1, -1}, x, l, n);
	return 0;
}