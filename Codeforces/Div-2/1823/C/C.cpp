#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxn = 1e7 + 5;
int spf[10000007];

void compute() {
	memset(spf, -1, sizeof(spf));
	for (int i = 2; i < mxn; i++) {
		if (spf[i] == -1) {
			spf[i] = i;
			for (int j = 2 * i; j < mxn; j += i) spf[j] = i;
		}
	}
}

void solve() {
	int N; cin >> N;
	set<int> factors;
	map<int, int> mp;
	for (int i = 0; i < N; i++) {
		int A; cin >> A;
		while (A > 1) {
			factors.insert(spf[A]);
			mp[spf[A]]++;
			A /= spf[A];
		}
	}

	int answer = 0;
	for (int i : factors) {
		int x = mp[i] >> 1ll;
		answer += x;
		mp[i] -= 2 * x;
	}

	int rem = 0;
	for (int i : factors) rem += mp[i];

	answer += (rem / 3);
	cout << answer << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	compute();

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}