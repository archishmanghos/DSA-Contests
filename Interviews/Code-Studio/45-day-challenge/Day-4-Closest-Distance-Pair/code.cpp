#include <bits/stdc++.h>
using namespace std;

long closestPair(pair<int, int>* pts, int n) {
	sort(pts, pts + n);
	set<pair<int, int>> s;

	long best_dist = 1e9;
	int j = 0;
	for (int i = 0; i < n; ++i) {
		int d = ceil(sqrt(best_dist));
		while (pts[i].first - pts[j].first >= d) {
			s.erase({pts[j].second, pts[j].first});
			j += 1;
		}

		auto it1 = s.lower_bound({pts[i].second - d, pts[i].first});
		auto it2 = s.upper_bound({pts[i].second + d, pts[i].first});

		for (auto it = it1; it != it2; ++it) {
			int dx = pts[i].first - it->second;
			int dy = pts[i].second - it->first;
			best_dist = min(best_dist, 1L * dx * dx + 1L * dy * dy);
		}
		s.insert({pts[i].second, pts[i].first});
	}
	return best_dist;
}
