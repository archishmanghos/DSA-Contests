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
	char repeatedCharacter(string s) {
		vector<int> cnt(26, 0);
		for (char c : s) {
			if (cnt[c - 'a'] == 1) return c;
			cnt[c - 'a'] += 1;
		}
		return '0';
	}
};


int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	Solution leetcode2IDE;
	string s1 = "abccbaacz";
	string output_1 = "c";
	if (leetcode2IDE.repeatedCharacter(s1) == output_1) {
		cout << "Sample #1 : Accepted" << endl;
	} else {
		cout << "Sample #1 : Wrong Answer" << endl;
	}

	string s2 = "abcdd";
	string output_2 = "d";
	if (leetcode2IDE.repeatedCharacter(s2) == output_2) {
		cout << "Sample #2 : Accepted" << endl;
	} else {
		cout << "Sample #2 : Wrong Answer" << endl;
	}




	return 0;
}
