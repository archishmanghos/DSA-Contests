#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, A; cin >> N;
	priority_queue<int, vector<int>, greater<int>> even, odd;
	for (int i = 1; i <= N; i++) {
		cin >> A;
		if (A % 2 == 0) {
			even.push(A);
		} else {
			odd.push(A);
		}

		if (even.size() > 2) even.pop();
		if (odd.size() > 2)odd.pop();
	}

	int ans = -1;

	if (even.size() > 1) {
		int x = even.top();
		even.pop();
		ans = max(ans, x + even.top());
	}

	if (odd.size() > 1) {
		int x = odd.top();
		odd.pop();
		ans = max(ans, x + odd.top());
	}

	cout << ans;
	return 0;
}
