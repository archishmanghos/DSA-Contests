#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <G:\DSA-Contests\archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = LLONG_MAX;

int N, K, P[mxN];

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> P[i];

	vector<vector<int>> v(N + 5);
	vector<int> index(N + 2, -1);
	set<int> done;
	int j = 0;
	for (int i = 1; i <= N; i++) {
		if (done.lower_bound(P[i]) == done.end()) {
			v[j].push_back(P[i]);
			index[P[i]] = j;
			done.insert(P[i]);
			if (v[j].size() == K) {
				while (v[j].size()) {
					index[v[j].back()] = (N + i - 1);
					done.erase(v[j].back());
					v[j].pop_back();
				}
			}
			j += 1;
		} else {
			int element = *done.lower_bound(P[i]);
			int indexElement = index[element];
			v[indexElement].push_back(P[i]);
			index[P[i]] = indexElement;
			done.erase(element);
			done.insert(P[i]);
			if (v[indexElement].size() == K) {
				while (v[indexElement].size()) {
					index[v[indexElement].back()] = (N + i - 1);
					done.erase(v[indexElement].back());
					v[indexElement].pop_back();
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (index[i] >= N) cout << (index[i] % N + 1) << '\n';
		else cout << -1 << '\n';
	}

	return 0;
}