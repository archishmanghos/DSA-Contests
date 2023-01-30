#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {
	int N; cin >> N;
	map<int, int> cnt;
	int A[N + 2];
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		cnt[A[i]] += 1;
	}

	vector<vector<int>> v;
	for (auto it : cnt) {
		v.push_back({it.first, it.second});
	}

	int answer = 0, pre = v[0][0], magnitude = v[0][1];
	for (int i = 1; i < v.size(); i++) {
		if (v[i][0] == pre + 1) {
			if (v[i][1] < magnitude) {
				answer += magnitude - v[i][1];
			}
		}
		else {
			answer += magnitude;
		}
		magnitude = v[i][1];
		pre = v[i][0];
	}

	answer += magnitude;
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