#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int getCommon(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> ump;
		for (int i : nums2) if (ump.find(i) == ump.end()) ump[i] = 1;

		for (int i : nums1) if (ump.find(i) != ump.end()) return i;
		return -1;
	}
};