#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> addToArrayForm(vector<int>& num, int k) {
		reverse (num.begin(), num.end());
		int n = num.size(), carry = 0, i = 0;

		while (carry > 0 or k > 0) {
			int a = (i < n ? num[i] : 0), b = k % 10;
			int add = a + b + carry;
			if (i < n) num[i++] = add % 10;
			else num.push_back(add % 10);
			carry = add / 10;
			k /= 10;
		}

		reverse (num.begin(), num.end());
		return num;
	}
};