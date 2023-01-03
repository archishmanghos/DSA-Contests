#include <bits/stdc++.h>
using namespace std;

string S;
int Q[4], P[4];
int64_t R;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> S;
	for (int i = 1; i <= 3; i++) cin >> Q[i];
	for (int i = 1; i <= 3; i++) cin >> P[i];
	cin >> R;

	int reqd[4] = {0};
	for (char c : S) {
		if (c == 'B') reqd[1] += 1;
		else if (c == 'S') reqd[2] += 1;
		else reqd[3] += 1;
	}

	auto rublesReqd = [&](int64_t hamburger) {
		int64_t newNeed[4], rubles = 0;
		for (int i = 1; i <= 3; i++) newNeed[i] = hamburger * reqd[i];
		for (int i = 1; i <= 3; i++) rubles += max(0LL, newNeed[i] - Q[i]) * P[i];
		return rubles;
	};

	int64_t low = 0, high = 1e15, answer = 0;
	while (low <= high) {
		int64_t mid = low + (high - low) / 2;
		if (rublesReqd(mid) > R) {
			high = mid - 1;
		} else {
			answer = mid;
			low = mid + 1;
		}
	}

	cout << answer;
	return 0;
}