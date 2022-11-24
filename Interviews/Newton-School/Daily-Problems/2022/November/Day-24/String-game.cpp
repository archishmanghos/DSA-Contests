#include <bits/stdc++.h>
using namespace std;

int main() {

	string s; cin >> s;
	bool bad = true;
	for (int i = 0; i < s.size(); i++) {
		bad &= ((!(i & 1) and (s[i] >= 'a' and s[i] <= 'z')) or ((i & 1) and (s[i] >= 'A' and s[i] <= 'Z')));
		if (!bad) {
			cout << "No";
			return 0;
		}
	}

	cout << "Yes";
	return 0;
}
