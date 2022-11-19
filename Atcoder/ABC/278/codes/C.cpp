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

	int n, q; cin >> n >> q;
	unordered_map<int, set<int>> follower;

	while (q--) {
		int t, a, b; cin >> t >> a >> b;
		if (t == 1) {
			follower[b].insert(a);
		} else if (t == 2) {
			if (follower.find(b) != follower.end()) {
				if (follower[b].find(a) != follower[b].end()) {
					follower[b].erase(a);
				}
			}
		} else {
			if (follower.find(b) != follower.end() and follower.find(a) != follower.end() and follower[b].find(a) != follower[b].end() and follower[a].find(b) != follower[a].end()) {
				cout << "Yes" << '\n';
			} else {
				cout << "No" << '\n';
			}
		}
	}
	return 0;
}