#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

string solution (string s) {
	string word = "", answer = "";
	vector<pair<int, string>> v;
	auto processWord = [&](string t) {
		int digit;
		string newWord = "";
		for (char c : t) {
			if (c >= '0' and c <= '9') digit = c;
			else newWord += c;
		}
		v.push_back({digit, newWord});
	};

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			processWord(word);
			word = "";
		} else {
			word += s[i];
		}
	}

	if (word.size() > 0) processWord(word);
	sort(v.begin(), v.end());
	for (auto [pos, word] : v) answer += word + ' ';
	answer.pop_back();
	return answer;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s = "is3 Cri1stiano 4the Rona2ldo 5best";
	cout << solution(s);
	return 0;
}