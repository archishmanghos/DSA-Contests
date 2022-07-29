#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <G:\DSA-Contests\archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = LLONG_MAX;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename num_t>
using ordered_multiset = tree<num_t, null_type, less_equal<num_t>, rb_tree_tag, tree_order_statistics_node_update>;

int shortestPulse(int n, int x, vector<int> &a) {
	map<int, int> cnt1, cnt2, cnt;
	ordered_multiset<int> os;

	for (int i = 0; i < n; i++) {
		cnt[a[i]] += 1;
		int x = os.order_of_key(a[i]), remElements = i + 1;
		if (cnt.find(a[i]) != cnt.end()) remElements -= cnt[a[i]];
		if (os.find(a[i]) == os.end()) {
			cnt2[a[i]] = remElements - x;
		} else {
			cnt2[a[i]] = max(cnt2[a[i]], remElements - x);
		}
		os.insert(a[i]);
	}

	os.clear();
	cnt.clear();
	for (int i = n - 1; i >= 0; i--) {
		cnt[a[i]] += 1;
		int x = os.order_of_key(a[i]), remElements = n - i;
		if (cnt.find(a[i]) != cnt.end()) remElements -= cnt[a[i]];
		if (os.find(a[i]) == os.end()) {
			cnt1[a[i]] = remElements - x;
		} else {
			cnt1[a[i]] = max(cnt1[a[i]], remElements - x);
		}
		os.insert(a[i]);
	}

	int ans = INT_MAX;
	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			int sz1 = i, sz2 = x / i;
			int minn1 = x / i, minn2 = i;
			int totalPresent1 = cnt[minn1], totalPresent2 = cnt[minn2];
			if (cnt1.find(minn1) != cnt1.end()) totalPresent1 += cnt1[minn1];
			if (cnt2.find(minn1) != cnt2.end()) totalPresent1 += cnt2[minn1];

			if (cnt1.find(minn2) != cnt1.end()) totalPresent2 += cnt1[minn2];
			if (cnt2.find(minn2) != cnt2.end()) totalPresent2 += cnt2[minn2];

			if (totalPresent1 >= sz1) ans = min(ans, sz1);
			if (totalPresent2 >= sz2) ans = min(ans, sz2);
		}
	}

	return (ans == INT_MAX ? -1 : ans);
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	int n, x; cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << shortestPulse(n, x, a);

	return 0;
}