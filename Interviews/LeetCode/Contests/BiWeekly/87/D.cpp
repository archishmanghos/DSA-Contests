#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <G:\DSA-Contests\archidebug.h>

#else
#define debug(x)
#endif

using namespace std;


class Solution {
public:
	long long minimumMoney(vector<vector<int>>& transactions) {
		long long lb = 0, ub = 0;
		sort(transactions.begin(), transactions.end(), [](const vector<int> &a, const vector<int> &b) {
			return ((a[0] - a[1]) > (b[0] - b[1]));
		});
		for (auto i : transactions) {
			ub += i[0];
		}

		debug(transactions)
		while (lb < ub) {
			long long mid = lb + (ub - lb) / 2, remMid = mid;
			for (auto i : transactions) {
				remMid -= i[0];
				if (remMid < 0) break;
				remMid += i[1];
			}

			cerr << lb << ' ' << ub << ' ' << mid << ' ' << remMid << '\n';
			if (remMid == 0) {
				return mid;
			} else if (remMid > 0) {
				ub = mid;
			} else {
				lb = mid + 1;
			}
		}

		return ub;
	}
};


int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Solution leetcode2IDE;
	vector<vector<int>> transactions1 = {{2, 1}, {5, 0}, {4, 2}};
	int output_1 = 10;
	if (leetcode2IDE.minimumMoney(transactions1) == output_1) {
		cout << "Sample #1 : Accepted" << endl;
	} else {
		cout << "Sample #1 : Wrong Answer" << endl;
	}

	vector<vector<int>> transactions2 = {{3, 0}, {0, 3}};
	int output_2 = 3;
	if (leetcode2IDE.minimumMoney(transactions2) == output_2) {
		cout << "Sample #2 : Accepted" << endl;
	} else {
		cout << "Sample #2 : Wrong Answer" << endl;
	}




	return 0;
}
