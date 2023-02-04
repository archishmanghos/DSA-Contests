#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {
	int N, Q; cin >> N >> Q;
	int A[N + 2];
	set<int> idxHavingNotSingleSum;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		if (A[i] > 9) idxHavingNotSingleSum.insert(i);
	}

	auto getDigitSum = [](int num) {
		int answer = 0;
		while (num) {
			answer += num % 10;
			num /= 10;
		}

		return answer;
	};

	while (Q--) {
		int type; cin >> type;
		if (type == 1) {
			int L, R; cin >> L >> R;
			auto firstIdx = idxHavingNotSingleSum.lower_bound(L);
			vector<int> toErase;
			while (firstIdx != idxHavingNotSingleSum.end()) {
				int idx = *firstIdx;
				if (idx > R) break;
				A[idx] = getDigitSum(A[idx]);
				if (A[idx] <= 9) toErase.push_back(idx);
				firstIdx++;
			}

			for (int i : toErase) idxHavingNotSingleSum.erase(i);
		} else {
			int idx; cin >> idx;
			cout << A[idx] << '\n';
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}