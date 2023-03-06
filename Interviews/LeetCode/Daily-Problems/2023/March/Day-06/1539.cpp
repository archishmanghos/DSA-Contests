#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findKthPositive(vector<int>& arr, int k) {
		int end = 0;
		for (int i : arr) {
			if (i - end > 1) {
				if (k - (i - end - 1) <= 0) return end + k;
				k -= i - end - 1;
			}
			end = i;
		}

		return end + k;
	}
};