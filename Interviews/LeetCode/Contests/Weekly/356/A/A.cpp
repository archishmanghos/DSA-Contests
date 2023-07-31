#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
		int answer = 0;
		for (int i : hours) answer += (i >= target);
		return answer;
	}
};