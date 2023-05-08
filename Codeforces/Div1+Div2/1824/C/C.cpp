#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int N, M; cin >> N >> M;
	int X, left = 0, right = 0;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		cin >> X;
		if (X == -1) ++left;
		else if (X == -2) ++right;
		else v.push_back(X);
	}

	int n = v.size();
	sort(v.begin(), v.end());
	auto ip = unique(v.begin(), v.begin() + n);
	v.resize(distance(v.begin(), ip));

	int answer = max(min(M, left + v.size()), min(M, right + v.size()));
	for (int i = 0; i < v.size(); i++) {
		int leftSeats = v[i] - 1;
		int designatedLeft = i;
		int rightSeats = M - v[i];
		int designatedRight = (v.size() - i - 1);
		int maxUsed = min(leftSeats, designatedLeft + left) + 1 + min(rightSeats, designatedRight + right);
		answer = max(answer, maxUsed);
	}

	cout << answer << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}