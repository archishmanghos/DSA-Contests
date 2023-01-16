#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> answer;
		int i = 0, start = -1;
		bool inserted = false;

		while (i < intervals.size()) {
			if (start == -1) {
				if (intervals[i][1] < newInterval[0]) {
					answer.push_back(intervals[i]);
				} else {
					if (intervals[i][0] > newInterval[1]) {
						answer.push_back(newInterval);
						inserted = true;
						break;
					}
					start = min(newInterval[0], intervals[i][0]);
				}
			} else {
				if (intervals[i][1] > newInterval[1]) {
					if (intervals[i][0] > newInterval[1]) {
						answer.push_back({start, max (newInterval[1], intervals[i - 1][1])});
						inserted = true;
						break;
					}
					answer.push_back({start, intervals[i][1]});
					i += 1;
					inserted = true;
					break;
				}
			}

			i += 1;
		}

		while (i < intervals.size()) answer.push_back(intervals[i++]);
		if (!inserted) {
			if (start == -1) answer.push_back(newInterval);
			else answer.push_back({start, max(newInterval[1], intervals.back()[1])});
		}

		return answer;
	}
};