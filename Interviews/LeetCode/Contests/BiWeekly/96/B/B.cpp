#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
		int64_t n = nums1.size(), sum = 0, operations = 0;
		vector<int> diff(n);
		for (int i = 0; i < n; i++) {
			diff[i] = nums2[i] - nums1[i];
			if (k > 0 and abs(diff[i]) % k != 0) return -1;
			if (diff[i] > 0) {
				if (k == 0) return -1;
				operations += diff[i] / k;
			}
			sum += diff[i];
		}

		if (sum != 0) return -1;
		return operations;
	}
};