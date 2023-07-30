#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isSmaller(string str1, string str2) {
		int n1 = str1.length(), n2 = str2.length();
		if (n1 < n2) return true;
		if (n2 < n1) return false;

		for (int i = 0; i < n1; i++) {
			if (str1[i] < str2[i]) return true;
			else if (str1[i] > str2[i]) return false;
		}

		return false;
	}
	string findDiff(string str1, string str2) {
		if (isSmaller(str1, str2)) swap(str1, str2);
		string str = "";
		int n1 = str1.length(), n2 = str2.length();
		reverse(str1.begin(), str1.end());
		reverse(str2.begin(), str2.end());
		int carry = 0;

		for (int i = 0; i < n2; i++) {
			int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);
			if (sub < 0) {
				sub += 10;
				carry = 1;
			}
			else carry = 0;
			str.push_back(sub + '0');
		}

		for (int i = n2; i < n1; i++) {
			int sub = ((str1[i] - '0') - carry);
			if (sub < 0) {
				sub +=  10;
				carry = 1;
			}
			else carry = 0;
			str.push_back(sub + '0');
		}

		reverse(str.begin(), str.end());
		return str;
	}

	// https://www.geeksforgeeks.org/difference-of-two-large-numbers/
	int cache[105][10][2][2];
	int dp(int idx, int preDig, int exceed, int start, string &x, int MOD = 1e9 + 7) {
		if (idx == x.size()) return 1;
		if (cache[idx][preDig][exceed][start] != -1) return cache[idx][preDig][exceed][start];

		int answer = 0;
		if (!start) {
			if (idx == 0) {
				for (int i = 0; i <= (x[idx] - '0'); i++) {
					answer = (answer % MOD + dp(idx + 1, i, (i < (x[idx] - '0')), i > 0, x) % MOD);
				}
			} else {
				for (int i = 0; i <= 9; i++) {
					answer = (answer % MOD + dp(idx + 1, i, 1, i > 0, x) % MOD) % MOD;
				}
			}
		} else {
			if (exceed) {
				if (preDig - 1 >= 0) answer = (answer % MOD + dp(idx + 1, preDig - 1, 1, 1, x) % MOD) % MOD;
				if (preDig + 1 <= 9) answer = (answer % MOD + dp(idx + 1, preDig + 1, 1, 1, x) % MOD) % MOD;
			} else {
				if (preDig - 1 >= 0 and preDig - 1 <= (x[idx] - '0')) answer = (answer % MOD + dp(idx + 1, preDig - 1, exceed | (preDig - 1 < (x[idx] - '0')), 1, x) % MOD) % MOD;
				if (preDig + 1 <= 9 and preDig + 1 <= (x[idx] - '0')) answer = (answer % MOD + dp(idx + 1, preDig + 1, exceed | (preDig + 1 < (x[idx] - '0')), 1, x) % MOD) % MOD;
			}
		}

		return cache[idx][preDig][exceed][start] = answer;
	}
	int countSteppingNumbers(string low, string high) {
		low = findDiff("1", low);
		int k = 0;
		for (int i = 0; i < low.size(); i++) {
			if (low[i] == '0') ++k;
			else break;
		}
		low = low.substr(k);
		int MOD = 1e9 + 7;
		memset(cache, -1, sizeof(cache));
		long answer = dp(0, 0, 0, 0, high);
		memset(cache, -1, sizeof(cache));
		answer = (answer - 1ll * dp(0, 0, 0, 0, low) % MOD + MOD) % MOD;
		return answer;
	}
};