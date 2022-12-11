#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s; cin >> s;
	string year = s.substr(0, 4);
	if (year != "2022") {
		if (year > "2022") {
			cout << "After";
		}
		else {
			cout << "Before";
		}
		return 0;
	}

	string month = s.substr(5, 2);
	if (month != "06") {
		if (month > "06") {
			cout << "After";
		}
		else {
			cout << "Before";
		}
		return 0;
	}

	string day = s.substr(8);
	if (day >= "20") {
		cout << "After";
		return 0;
	}
	cout << "Before";
	return 0;
}