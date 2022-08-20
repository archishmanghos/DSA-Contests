#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <G:\DSA-Contests\archidebug.h>

#else
#define debug(x)
#endif

using namespace std;


class Solution {
public:
	bool check(string s) {
		if (s.size() == 1) return false;
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == '1' and s[i - 1] == '0') return true;
		}

		return false;
	}
	int secondsToRemoveOccurrences(string s) {
		int ans = 0;
		while (check(s)) {
			ans += 1;
			for (int i = 1; i < s.size(); i++) {
				if (s[i] == '1' and s[i - 1] == '0') {
					swap(s[i], s[i - 1]);
					i += 1;
				}
			}
		}

		return ans;
	}
};


int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Solution leetcode2IDE;
	string s1 = "0110101";
	int output_1 = 4;
	if (leetcode2IDE.secondsToRemoveOccurrences(s1) == output_1) {
		cout << "Sample #1 : Accepted" << endl;
	} else {
		cout << "Sample #1 : Wrong Answer" << endl;
	}

	string s2 = "11100";
	int output_2 = 0;
	if (leetcode2IDE.secondsToRemoveOccurrences(s2) == output_2) {
		cout << "Sample #2 : Accepted" << endl;
	} else {
		cout << "Sample #2 : Wrong Answer" << endl;
	}




	return 0;
}
