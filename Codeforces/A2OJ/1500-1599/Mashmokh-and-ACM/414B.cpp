#include <bits/stdc++.h>
#define int long long
using namespace std;

int N, K;
int cache[2005][2005];

int dp(int idx, int cur, int MOD = 1e9 + 7) {
	if (idx == K) return 1;
	int &answer = cache[idx][cur];
	if (answer != -1) return answer;

	answer = 0;
	for (int i = cur; i <= N; i += cur) answer = (answer + dp(idx + 1, i) % MOD) % MOD;
	return answer;
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	cin >> N >> K;
	memset(cache, -1, sizeof(cache));

	int answer = dp(0, 1);
	cout << answer;
	return 0;
}