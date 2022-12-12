#include <bits/stdc++.h>
using namespace std;

int getDist(int start, int end, int k, vector<int> &v1, vector<int> &v2) {
	int ans = 1e9;
	for (int i = start; i <= end; i++) {
		int travelThis = 0, travelOther = 0;
		if (i > 0) {
			travelThis = v1[i - 1] * 2; // another v1[i - 1] for returning back to 0
		}
		if (i < k) {
			travelOther = v2[k - i - 1];
		}

		ans = min(ans, travelThis + travelOther);
	}

	return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, x; cin >> n >> k;
	vector<int> pos, neg;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 0) {
			k -= 1;
		} else if (x > 0) {
			pos.push_back(x);
		} else {
			neg.push_back(-x);
		}
	}

	reverse(neg.begin(), neg.end());
	int ans = 0;
	if (k == 0) {
		return ans;
	}

	// taking i positives from 0 to min (size of pos, k)
	int start = 0 + max((int)0, (k - (int)neg.size()));
	int end = min((int)pos.size(), k);
	ans = getDist(start, end, k, pos, neg);

	// taking i negatives from 0 to min (size of pos, k)
	start = 0 + max((int)0, (k - (int)pos.size()));
	end = min((int)neg.size(), k);
	ans = min(ans, getDist(start, end, k, neg, pos));

	cout << ans;
	return 0;
}