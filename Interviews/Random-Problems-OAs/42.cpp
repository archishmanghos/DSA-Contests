#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
// #include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

long computePossibilities(long k, vector<int> &heights, vector<int> &points) {
	int n = heights.size();
	function<int(int, int, vector<int>)> dp = [&](int idx, int preIdx, vector<int> taken) {
		if (idx == n) {
			long sum = 0;
			for (int i : taken) sum += points[i];
			return sum >= k ? 1l : 0l;
		}

		long answer = dp(idx + 1, preIdx, taken);
		if (preIdx == 0 or heights[idx] >= heights[preIdx - 1]) {
			taken.push_back(idx);
			answer += dp(idx + 1, idx + 1, taken);
			taken.pop_back();
		}

		return answer;
	};

	return dp(0, 0, {});
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int K; cin >> K;
	int N; cin >> N;
	vector<int> h(N), p(N);
	for (int i = 0; i < N; i++) cin >> h[i];
	for (int i = 0; i < N; i++) cin >> p[i];

	cout << computePossibilities(K, h, p);
	return 0;
}