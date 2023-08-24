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

	string integerToString (int x) {
		if (x == 0) return "0";
		string answer = "";
		while (x) {
			answer += (x % 10) + '0';
			x /= 10;
		}

		reverse(answer.begin(), answer.end());
		return answer;
	}

	int powerOf10(int power) {
		int answer = 1;
		while (power--) {
			answer *= 10;
		}

		return answer;
	}

	int cache[12][2][12][2][22][12];

	int dp(int idx, int start, int startIdx, int exceed, int sum, int even, string & nums, int k) {
		if (start) {
			int totalDigits = (int)nums.size() - startIdx;
			if (totalDigits & 1) return 0;
			if (even > (totalDigits / 2)) return 0;
		}
		if (idx == nums.size()) {
			int totalDigits = (int)nums.size() - startIdx;
			if (totalDigits & 1) return 0;
			return (sum == 0 and even == (totalDigits / 2));
		}

		if (cache[idx][start][startIdx][exceed][sum][even] != -1) return cache[idx][start][startIdx][exceed][sum][even];
		int answer = 0;

		int end = (exceed ? 9 : (nums[idx] - '0'));
		for (int i = 0; i <= end; i++) {
			int preSum = sum;
			bool preStart = start;
			int preEven = even;
			if (!start and i > 0) {
				start = true;
				startIdx = idx;
			}
			if (start) sum = (sum + (i * powerOf10((int)nums.size() - idx - 1))) % k;
			if (start) even += (i % 2 == 0);
			answer += dp(idx + 1, start, startIdx, (exceed | (i < end)), sum, even, nums, k);
			sum = preSum;
			start = preStart;
			even = preEven;
		}

		return cache[idx][start][startIdx][exceed][sum][even] = answer;
	}
	int numberOfBeautifulIntegers(int low, int high, int k) {
		string lowN = findDiff(integerToString(low), "1");
		string highN = integerToString(high);

		memset(cache, -1, sizeof(cache));
		int highAns = dp(0, 0, 0, 0, 0, 0, highN, k);
		memset(cache, -1, sizeof(cache));
		int lowAns = dp(0, 0, 0, 0, 0, 0, lowN, k);
		int answer = highAns - lowAns;
		return answer;
	}
};