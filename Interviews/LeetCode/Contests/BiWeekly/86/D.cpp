#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <G:\DSA-Contests\archidebug.h>

#else
#define debug(x)
#endif

using namespace std;


class Solution {
public:
	int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
		int n = chargeTimes.size();
		vector<pair<int64_t, int>> v;
		for (int i = 0; i < n; i++) {
			v.push_back({runningCosts[i], chargeTimes[i]});
		}

		sort(v.begin(), v.end());
		for (int i = 1; i < n; i++) {
			v[i].first += v[i - 1].first;
		}

		for (int i = 0; i < n; i++) cout << v[i].first << ' ' << v[i].second << '\n';
		cout << '\n';
		int ans1 = 0, maxx = 0;
		for (int i = 0; i < n; i++) {
			maxx = max(maxx, v[i].second);
			int64_t sum = maxx + (i + 1) * v[i].first;
			cout << sum << '\n';
			if (sum <= budget) {
				ans1 += 1;
			} else {
				break;
			}
		}

		for (int i = n - 1; i > 0; i--) v[i].first -= v[i - 1].first;
		sort(v.begin(), v.end(), [](const pair<int64_t, int> &a, const pair<int64_t, int> &b) {
			return a.second < b.second;
		});

		for (int i = 1; i < n; i++) {
			v[i].first += v[i - 1].first;
		}

		for (int i = 0; i < n; i++) cout << v[i].first << ' ' << v[i].second << '\n';
		cout << '\n';
		int ans2 = 0;
		maxx = 0;
		for (int i = 0; i < n; i++) {
			maxx = max(maxx, v[i].second);
			int64_t sum = maxx + (i + 1) * v[i].first;
			cout << sum << '\n';
			if (sum <= budget) {
				ans2 += 1;
			} else {
				break;
			}
		}

		return max(ans1, ans2);
	}
};


int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Solution leetcode2IDE;
	vector<int> chargeTimes1 = {3, 6, 1, 3, 4};
	vector<int> runningCosts1 = {2, 1, 3, 4, 5};
	int budget1 = 25;
	int output_1 = 3;
	if (leetcode2IDE.maximumRobots(chargeTimes1, runningCosts1, budget1) == output_1) {
		cout << "Sample #1 : Accepted" << endl;
	} else {
		cout << "Sample #1 : Wrong Answer" << endl;
	}

	vector<int> chargeTimes2 = {11, 12, 19};
	vector<int> runningCosts2 = {10, 8, 7};
	int budget2 = 19;
	int output_2 = 0;
	if (leetcode2IDE.maximumRobots(chargeTimes2, runningCosts2, budget2) == output_2) {
		cout << "Sample #2 : Accepted" << endl;
	} else {
		cout << "Sample #2 : Wrong Answer" << endl;
	}




	return 0;
}
