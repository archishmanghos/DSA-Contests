#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <G:\DSA-Contests\archidebug.h>

#else
#define debug(x)
#endif

using namespace std;


class Solution {
public:
	string shiftingLetters(string s, vector<vector<int>>& shifts) {
		int n = s.size();
		vector<int> pref(n + 1, 0);
		for (auto i : shifts) {
			int l = i[0], r = i[1], d = i[2];
			if (d == 0) {
				pref[l] -= 1;
				pref[r + 1] += 1;
			} else {
				pref[l] += 1;
				pref[r + 1] -= 1;
			}
		}

		for (int i = 1; i < n; i++) {
			pref[i] += pref[i - 1];
		}

		for (int i = 0; i < n; i++) {
			if (pref[i] < 0) {
				int shift = abs(pref[i]) % 26;
				if (shift > (s[i] - 'a')) {
					s[i] = (((s[i] - 'a') + (26 - shift)) + 'a');
				} else {
					s[i] = (s[i] - shift);
				}
			} else {
				int shift = pref[i] % 26;
				if (shift > (25 - (s[i] - 'a'))) {
					s[i] = (((s[i] - 'a') - (26 - shift)) + 'a');
				} else {
					s[i] = (s[i] + shift);
				}
			}
		}

		return s;
	}
};


int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Solution leetcode2IDE;
	string s1 = "abc";
	vector<vector<int>> shifts1 = {{0, 1, 0}, {1, 2, 1}, {0, 2, 1}};
	string output_1 = "ace";
	if (leetcode2IDE.shiftingLetters(s1, shifts1) == output_1) {
		cout << "Sample #1 : Accepted" << endl;
	} else {
		cout << "Sample #1 : Wrong Answer" << endl;
	}

	string s2 = "dztz";
	vector<vector<int>> shifts2 = {{0, 0, 0}, {1, 1, 1}};
	string output_2 = "catz";
	if (leetcode2IDE.shiftingLetters(s2, shifts2) == output_2) {
		cout << "Sample #2 : Accepted" << endl;
	} else {
		cout << "Sample #2 : Wrong Answer" << endl;
	}




	return 0;
}
