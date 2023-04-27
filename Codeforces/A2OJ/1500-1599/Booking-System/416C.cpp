#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N; cin >> N;
	priority_queue<vector<int>> pq;
	for (int i = 1; i <= N; i++) {
		int C, P; cin >> C >> P;
		pq.push({P, C, i});
	}

	int K; cin >> K;
	multiset<pair<int, int>> ms;
	for (int i = 1; i <= K; i++) {
		int R; cin >> R;
		ms.insert({R, i});
	}

	vector<vector<int>> answer;
	int income = 0;
	while (!pq.empty()) {
		auto it = pq.top(); pq.pop();
		int capacity = it[1];
		if (ms.size() == 0 or (*ms.rbegin()).first < capacity) continue;

		income += it[0];
		auto table = *ms.lower_bound({capacity, numeric_limits<int>::min()});
		ms.erase(ms.find(table));
		answer.push_back({it[2], table.second});
	}

	cout << answer.size() << ' ' << income << '\n';
	for (auto table : answer) cout << table[0] << ' ' << table[1] << '\n';
	return 0;
}