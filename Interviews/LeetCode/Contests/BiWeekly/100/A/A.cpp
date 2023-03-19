#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int distMoney(int money, int children) {
		money -= children;
		if (money < 0) return -1;
		int answer = 0;
		for (int i = 1; i <= children; i++) {
			if (money < 7) {
				if (money != 3) return answer;
				else {
					if (children == 1) return -1;
					if (i < children) return answer;
					return answer - 1;
				}
			} else {
				answer += 1;
				money -= 7;
			}
		}

		return (money ? answer - 1 : answer);
	}
};