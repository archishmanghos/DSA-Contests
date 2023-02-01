#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int P[100100], A[100100];

void solve() {
	int N, M, D; cin >> N >> M >> D;
	vector<int> pos(N + 2, -1);
	for (int i = 1; i <= N; i++) {
		cin >> P[i];
		pos[P[i]] = i;
	}

	auto check = [&](int pos1, int pos2) {
		return (pos2 >= pos1 + 1 and pos2 <= pos1 + D);
	};

	auto getSwaps = [&](int pos1, int pos2) {
		int answer = 0;

		int diff = (D + 1) - (pos2 - pos1);
		int next = min(pos2 + diff, N);
		answer += next - pos2;
		pos2 = next;

		if (pos2 - pos1 <= D) {
			diff = (D + 1) - (pos2 - pos1);
			next = max(pos1 - diff, 1ll);
			answer += pos1 - next;
			pos1 = next;
		}

		if (pos2 - pos1 <= D) return (int)1e9;
		return answer;
	};

	bool check0 = false;
	for (int i = 1; i <= M; i++) {
		cin >> A[i];
		if (i > 1) check0 |= !check(pos[A[i - 1]], pos[A[i]]);
	}

	if (check0) {
		cout << 0 << '\n';
		return;
	}

	int answer = 1e9;
	for (int i = 2; i <= M; i++) {
		int crossSwap = pos[A[i]] - pos[A[i - 1]];
		answer = min(answer, min(crossSwap, getSwaps(pos[A[i - 1]], pos[A[i]])));
	}

	cout << answer << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--)
		solve();
	return 0;
}

// I just got 3 WAs because of returning while taking input and I have been doing CF for 2 years now. FML.