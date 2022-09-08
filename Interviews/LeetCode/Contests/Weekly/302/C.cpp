#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <G:\DSA-Contests\archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = LLONG_MAX;



class Solution {
public:
	string getTrimmed(string num, int trim) {
		int trimVal = (int)num.size() - trim;
		string toTrim = num.substr(trimVal);
		return toTrim;
	}
	vector<pair<string, int>> getAns(vector<pair<string, int>> v, int trim, map<string, vector<string>> &preCalculateTrim) {
		vector<pair<string, int>> finalAns;
		multiset<pair<string, int>> ans;
		for (int i = 0; i < v.size(); i++) {
			string trimmedVal = preCalculateTrim[v[i].first][trim - 1];
			int index = v[i].second;
			ans.insert({trimmedVal, index});
		}

		for (auto i : ans) finalAns.push_back(i);
		return finalAns;
	}
	vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
		int n = nums.size(), n1 = queries.size(), j = 0;
		vector<pair<string, int>> v(n);
		map<string, vector<string>> preCalculateTrim;
		for (int i = 0; i < n; i++) {
			v[i] = {nums[i], i};
			for (int j = 1; j <= nums[i].size(); j++) {
				preCalculateTrim[nums[i]].push_back(getTrimmed(nums[i], j));
			}
		}

		vector<int> ans(n1);
		for (vector<int> q : queries) {
			int k = q[0] - 1, trim = q[1];
			vector<pair<string, int>> newV = getAns(v, trim, preCalculateTrim);
			ans[j++] = newV[k].second;
		}

		return ans;
	}
};


int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	Solution leetcode2IDE;
	vector<string> nums1 = {"102", "473", "251", "814"};
	vector<vector<int>> queries1 = {{1, 1}, {2, 3}, {4, 2}, {1, 2}};
	vector<int> output_1 = {2, 2, 1, 0};
	if (leetcode2IDE.smallestTrimmedNumbers(nums1, queries1) == output_1) {
		cout << "Sample #1 : Accepted" << endl;
	} else {
		cout << "Sample #1 : Wrong Answer" << endl;
	}

	vector<string> nums2 = {"24", "37", "96", "04"};
	vector<vector<int>> queries2 = {{2, 1}, {2, 2}};
	vector<int> output_2 = {3, 0};
	if (leetcode2IDE.smallestTrimmedNumbers(nums2, queries2) == output_2) {
		cout << "Sample #2 : Accepted" << endl;
	} else {
		cout << "Sample #2 : Wrong Answer" << endl;
	}




	return 0;
}
