#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
		unordered_map<string, int> ump;
		for (string s : positive_feedback) ump[s] = 3;
		for (string s : negative_feedback) ump[s] = -1;

		unordered_map<int, int> points;
		int n = report.size();
		for (int i = 0; i < n; i++) {
			string s = "";
			for (char c : report[i]) {
				if (c == ' ') {
					if (ump.find(s) != ump.end()) points[student_id[i]] += ump[s];
					s = "";
				} else {
					s += c;
				}
			}
			if (ump.find(s) != ump.end()) points[student_id[i]] += ump[s];
		}

		vector<vector<int>> v;
		for (auto i : points) {
			v.push_back({i.second, i.first});
		}

		sort(v.begin(), v.end(), [](const vector<int> &a, const vector<int> &b) {
			if (a[0] != b[0]) return a[0] > b[0];
			return a[1] < b[1];
		});

		vector<int> ans;
		for (int i = 0; i < k; i++) {
			ans.push_back(v[i][1]);
		}

		return ans;
	}
};
