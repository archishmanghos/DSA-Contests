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

int N, X, Y;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	cin >> N >> X >> Y;
	queue<pair<char, pair<int, int>>> bfs;
	bfs.push({'r', {1, N}});
	bfs.push({'b', {0, -1}});

	int ans = 0;
	while (!bfs.empty()) {
		pair<char, pair<int, int>> p = bfs.front();
		bfs.pop();
		if (p.first == 'r') {
			int red = p.second.first, redLevel = p.second.second;
			if (red) {
				if (redLevel > 1) {
					bfs.push({'r', {red, redLevel - 1}});
					bfs.push({'b', {red * X, redLevel}});
				}
			}
		} else {
			int blue = p.second.first, blueLevel = p.second.second;
			if (blue) {
				if (blueLevel > 1) {
					bfs.push({'r', {blue, blueLevel - 1}});
					bfs.push({'b', {blue * Y, blueLevel - 1}});
				} else {
					ans += blue;
				}
			}
		}
	}

	cout << ans;

	return 0;
}