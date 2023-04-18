#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int A, N; cin >> N;
	int twentyFive = 0, fifty = 0;
	for (int i = 1; i <= N; i++) {
		cin >> A;
		if (A == 25) twentyFive++;
		else if (A == 50) {
			fifty++;
			if (twentyFive) twentyFive--;
			else {
				cout << "NO";
				return 0;
			}
		} else {
			if (fifty and twentyFive) fifty--, twentyFive--;
			else if (twentyFive > 2) twentyFive -= 3;
			else {
				cout << "NO";
				return 0;
			}
		}
	}

	cout << "YES";
	return 0;
}