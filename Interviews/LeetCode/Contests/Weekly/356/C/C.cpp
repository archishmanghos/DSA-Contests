#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string minimumString(string a, string b, string c) {
		vector<string> v;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);

		sort(v.begin(), v.end());
		string answer = "-1";

		do {
			string x = "";
			x += v[0];

			size_t found = x.find(v[1]);
			if (found == string::npos) {
				int k = 0;
				for (int i = x.size() - 1; i >= 0; i--) {
					string x1 = x.substr(i);
					string x2 = v[1].substr(0, x.size() - i);
					if (x1 == x2) {
						k = x.size() - i;
					}
				}

				if (k < v[1].size()) x += v[1].substr(k);
			}

			size_t found1 = x.find(v[2]);
			if (found1 == string::npos) {
				int k = 0;
				for (int i = x.size() - 1; i >= 0; i--) {
					string x1 = x.substr(i);
					string x2 = v[2].substr(0, x.size() - i);
					if (x1 == x2) {
						k = x.size() - i;
					}
				}
				if (k < v[2].size()) x += v[2].substr(k);
			}


			if (answer == "-1" or answer.size() > x.size()) answer = x;
			else if (x.size() == answer.size()) answer = min(answer, x);
		} while (next_permutation(v.begin(), v.end()));

		return answer;
	}
};