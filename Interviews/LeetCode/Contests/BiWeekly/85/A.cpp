#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <G:\DSA-Contests\archidebug.h>

#else
#define debug(x)
#endif

using namespace std;


class Solution {
public:
	int minimumRecolors(string blocks, int k) {
		int n = blocks.size(), ans = 0;
		for (int i = 0; i < k; i++) {
			ans += blocks[i] == 'W';
		}

		int now = ans;
		for (int i = k; i < n; i++) {
			now -= blocks[i - k] == 'W';
			now += blocks[i] == 'W';
			ans = min(ans, now);
		}

		return ans;
	}
};


int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Solution leetcode2IDE;
	string blocks1 = "WBBWWBBWBW";
	int k1 = 7;
	int output_1 = 3;
	if (leetcode2IDE.minimumRecolors(blocks1, k1) == output_1) {
		cout << "Sample #1 : Accepted" << endl;
	} else {
		cout << "Sample #1 : Wrong Answer" << endl;
	}

	string blocks2 = "WBWBBBW";
	int k2 = 2;
	int output_2 = 0;
	if (leetcode2IDE.minimumRecolors(blocks2, k2) == output_2) {
		cout << "Sample #2 : Accepted" << endl;
	} else {
		cout << "Sample #2 : Wrong Answer" << endl;
	}




	return 0;
}
