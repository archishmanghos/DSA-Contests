#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		if (a.size() < b.size()) swap (a, b);
		int carry = 0, na = a.size(), nb = b.size();
		string answer = "";
		reverse (a.begin(), a.end());
		reverse (b.begin(), b.end());
		for (int i = 0; i < na; i++) {
			int aa = a[i] - '0';
			int bb = (i < nb ? b[i] - '0' : 0);
			int sum = aa + bb + carry;
			if (sum == 0) {
				answer += '0';
				carry = 0;
			} else if (sum == 1) {
				answer += '1';
				carry = 0;
			} else if (sum == 2) {
				answer += '0';
				carry = 1;
			} else {
				answer += '1';
				carry = 1;
			}
		}

		if (carry) answer += '1';
		reverse (answer.begin(), answer.end());
		return answer;
	}
};