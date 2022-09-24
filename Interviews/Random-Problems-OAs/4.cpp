#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

vector<string> f(string &s, string &t) {
	int n1 = s.size(), n2 = t.size();
	vector<string> words, wordsGiven, ans;
	string temp = "";

	for (int i = 0; i < n1; i++) {
		if (s[i] != ' ') {
			temp += s[i];
		} else {
			if (temp.size() > 0) {
				words.push_back(temp);
			}
			temp = "";
		}
	}
	if (temp.size() > 0) {
		words.push_back(temp);
	}
	temp = "";

	for (int i = 0; i < n2; i++) {
		if (t[i] != ' ') {
			temp += t[i];
		} else {
			if (temp.size() > 0) {
				wordsGiven.push_back(temp);
			}
			temp = "";
		}
	}
	if (temp.size() > 0) {
		wordsGiven.push_back(temp);
	}
	temp = "";
	int i = 0, j = 0;
	while (i < words.size()) {
		if (j == wordsGiven.size()) {
			ans.push_back(words[i]);
		} else {
			if (words[i] == wordsGiven[j]) {
				j += 1;
			} else {
				ans.push_back(words[i]);
			}
		}
		i += 1;
	}

	return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s = "I am using Hackerrank to improve programming", t = "am Hackerrank to improve";
	vector<string> ans = f(s, t);
	for (string st : ans) {
		cout << st << '\n';
	}
	return 0;
}