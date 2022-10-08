#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M; cin >> N >> M;
	map<int, set<int>> mp;
	for (int i = 1; i <= M; i++) {
		int K; cin >> K;
		vector<int> X(K);
		for (int j = 0; j < K; j++) {
			cin >> X[j];
		}

		for (int j = 0; j < K; j++) {
			for (int k = 0; k < K; k++) {
				if (k != j) {
					mp[X[j]].insert(X[k]);
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (mp[i].size() < N - 1) {
			cout << "No";
			return 0;
		}
	}

	cout << "Yes";
	return 0;
}