#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int helper (int A, int B, int C, int D) {
		int answer = 0;
		while (A > C) {
			A >>= 1;
			answer += 1;
		}
		while (B > D) {
			B >>= 1;
			answer += 1;
		}

		return answer;
	}
	int carpetBox(int A, int B, int C, int D) {
		return (min (helper(A, B, C, D), helper (B, A, C, D)));
	}
};