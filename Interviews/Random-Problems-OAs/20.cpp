#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 1e6;
int prime[mxN];

void soe() {
	prime[0] = prime[1] = 0;
	for (int i = 2; i * i <= mxN; i++) {
		if (prime[i]) {
			for (int j = i * i; j <= mxN; j += i) prime[j] = 0;
		}
	}
}

void listt(int N, int K) {
	memset(prime, 1, sizeof(prime));
	soe();

	vector<int> ans;
	int i = 2;
	while (N > 0) {
		if (prime[i] and i % 10 == K) ans.emplace_back(i), N--;
		i += 1;
	}

	ans.emplace_back(2);
	ans.emplace_back(5);
	sort(ans.begin(), ans.end());

	for (int i : ans) cout << i << ' ';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K; cin >> N >> K;
	listt(N, K);
	return 0;
}