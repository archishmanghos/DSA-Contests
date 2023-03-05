#include <bits/stdc++.h>
using namespace std;

class Solution {
	int spf[1000010];
public:
	void soe() {
		memset(spf, -1, sizeof(spf));
		for (int i = 2; i * i <= 1000000; i++) {
			if (spf[i] == -1) {
				spf[i] = i;
				for (int j = i * i; j <= 1000000; j += i) spf[j] = i;
			}
		}
	}
	int findValidSplit(vector<int>& nums) {
		soe();
		unordered_map<int, int> suffix, prefix;
		set<int> factors;
		int x = nums[0];
		while (x > 1) {
			factors.insert(spf[x]);
			prefix[spf[x]] += 1;
			x /= spf[x];
		}

		for (int i = 1; i < nums.size(); i++) {
			int x = nums[i];
			while (x > 1) {
				suffix[spf[x]] += 1;
				x /= spf[x];
			}
		}

		vector<int> common(1000005, 0);
		bool noCommon = true;
		int commonFactors = 0;

		for (int i : factors) {
			if (suffix.find(i) != suffix.end()) {
				noCommon = false;
				common[i] = min(suffix[i], prefix[i]);
				commonFactors += min(suffix[i], prefix[i]);
			}
		}

		if (noCommon) return 0;

		for (int i = 1; i < nums.size() - 1; i++) {
			int x = nums[i];
			while (x > 1) {
				suffix[spf[x]] -= 1;
				if (suffix[spf[x]] == 0) {
					if (common[spf[x]]) {
						common[spf[x]] -= 1;
						commonFactors -= 1;
					}
				} else {
					if (common[spf[x]] == 0) commonFactors += 1;
					common[spf[x]] += 1;
				}
				x /= spf[x];
				if (commonFactors == 0) return i;
			}
		}

		return -1;
	}
};