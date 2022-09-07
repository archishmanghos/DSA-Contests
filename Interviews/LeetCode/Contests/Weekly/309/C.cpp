#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <G:\DSA-Contests\archidebug.h>

#else
#define debug(x)
#endif

using namespace std;


class Solution {
public:
	int longestNiceSubarray(vector<int>& nums) {
		int n = nums.size(), j = 0, ans = 1, mask = 0;
		for (int i = 0; i < n; i++) {
			while ((mask & nums[i]) != 0) mask ^= nums[j++];
			mask |= nums[i];
			ans = max(ans, i - j + 1);
		}

		return ans;
	}
};


int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Solution leetcode2IDE;
	vector<int> nums1 = {1, 3, 8, 48, 10};
	int output_1 = 3;
	if (leetcode2IDE.longestNiceSubarray(nums1) == output_1) {
		cout << "Sample #1 : Accepted" << endl;
	} else {
		cout << "Sample #1 : Wrong Answer" << endl;
	}

	vector<int> nums2 = {3, 1, 5, 11, 13};
	int output_2 = 1;
	if (leetcode2IDE.longestNiceSubarray(nums2) == output_2) {
		cout << "Sample #2 : Accepted" << endl;
	} else {
		cout << "Sample #2 : Wrong Answer" << endl;
	}

	vector<int> nums3 = {84139415, 693324769, 614626365, 497710833, 615598711, 264, 65552, 50331652, 1, 1048576, 16384, 544, 270532608, 151813349, 221976871, 678178917, 845710321, 751376227, 331656525, 739558112, 267703680};
	int output_3 = 8;
	if (leetcode2IDE.longestNiceSubarray(nums3) == output_3) {
		cout << "Sample #3 : Accepted" << endl;
	} else {
		cout << "Sample #3 : Wrong Answer" << endl;
	}


	return 0;
}
