#include <bits/stdc++.h>
using namespace std;

bool checkIfSubsequence(string s, string t) {
	if (t.size() != s.size() - 1) return false;
	int i = 0;
	for (int j = 0; j < s.size(); j++) {
		if (i == t.size()) return true;
		if (s[j] == t[i]) i++;
	}

	return i == t.size();
}

int32_t main() {

	int n; cin >> n;
	vector<string> words(n);
	for (int i = 0; i < n; i++) cin >> words[i];

	sort(words.begin(), words.end(), [](const string & a, const string & b) {
		return a.size() < b.size();
	});

	vector<int> cache(n, 1);
	int length = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (checkIfSubsequence(words[i], words[j]) and 1 + cache[j] > cache[i]) {
				cache[i] = 1 + cache[j];
			}
		}
		length = max(length, cache[i]);
	}

	cout << length;
	return 0;
}