#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
		vector<vector<int>> temp;
		for (int i = 0; i < score.size(); i++) temp.push_back({score[i][k], i});
		sort(temp.begin(), temp.end(), greater<vector<int>>());

		vector<vector<int>> answer(score.size(), vector<int>(score[0].size()));
		for (int i = 0; i < score.size(); i++) {
			for (int j = 0; j < score[0].size(); j++) {
				answer[i][j] = score[temp[i][1]][j];
			}
		}

		return answer;
	}
};