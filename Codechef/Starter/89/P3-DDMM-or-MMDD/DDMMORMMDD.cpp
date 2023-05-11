#include <bits/stdc++.h>
using namespace std;

void solve() {
	string S; cin >> S;
	int expectedDay = (S[0] - '0') * 10 + (S[1] - '0');
	int expectedMonth = (S[3] - '0') * 10 + (S[4] - '0');
	int expectedYear = (S[6] - '0') * 1000 + (S[7] - '0') * 100 + (S[8] - '0') * 10 + (S[9] - '0');

	auto checkLeap = [&]() {
		if (expectedYear % 400 == 0) return true;
		if (expectedYear % 100 == 0) return false;
		return (expectedYear % 4 == 0);
	};

	int m[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (checkLeap()) ++m[1];

	int a = 0, b = 0;
	if (expectedMonth <= 12) if (expectedDay <= m[expectedMonth - 1]) a = 1;
	if (expectedDay <= 12) if (expectedMonth <= m[expectedDay - 1]) b = 1;

	if (a and b) cout << "BOTH" << '\n';
	else cout << (a ? "DD/MM/YYYY" : "MM/DD/YYYY") << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}