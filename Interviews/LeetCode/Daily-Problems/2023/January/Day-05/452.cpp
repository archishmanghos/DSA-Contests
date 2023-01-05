#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points) {
		sort (points.begin(), points.end());
		int end = points[0][1], answer = 1;
		for (int i = 1; i < points.size(); i++) {
			if (points[i][0] > end) {
				answer += 1;
				end = points[i][1];
			} else {
				end = min(end, points[i][1]);
			}
		}

		return answer;
	}
};