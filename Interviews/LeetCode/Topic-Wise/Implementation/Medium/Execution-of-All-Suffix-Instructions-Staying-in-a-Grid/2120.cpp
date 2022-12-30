#include <bits/stdc++.h>
using namespace std;

class Robot {
private:
	int n;
	string s;
	vector<int> startPos;

	int getMoves (int idx) {
		int x = startPos[0], y = startPos[1];
		int ans = 0;
		for (int i = idx; i < s.size(); i++) {
			int nextt = nextPos (x, y, s[i]);
			if (nextt == -1) break;
			x = nextt / n;
			y = nextt % n;
			ans += 1;
		}

		return ans;
	}

	int nextPos (int x, int y, char ch) {
		int dx[4] = {0, 0, -1, 1}, dy[4] = { -1, 1, 0, 0};
		int idx;
		if (ch == 'L') idx = 0;
		else if (ch == 'R') idx = 1;
		else if (ch == 'U') idx = 2;
		else idx = 3;

		x += dx[idx], y += dy[idx];
		if (isValid (x, y)) return (x * n + y);
		return { -1};
	}

	bool isValid (int x, int y) {
		return (x >= 0 and x < n and y >= 0 and y < n);
	}

public:
	Robot (int n, string s, vector<int> startPos) {
		this->n = n;
		this->s = s;
		this->startPos = startPos;
	}

	vector<int> getAns () {
		vector<int> ans (s.size());
		for (int i = 0; i < s.size(); i++) {
			ans[i] = getMoves (i);
		}

		return ans;
	}
};

class Solution {
public:
	vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
		Robot obj (n, s, startPos);
		return obj.getAns();
	}
};