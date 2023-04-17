#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	string N; cin >> N;
	int count = 0;
	for (char c : N) count += (c == '4' or c == '7');

	if (count == 0) {
		cout << "NO";
		return 0;
	}

	while (count) {
		if (count % 10 != 4 and count % 10 != 7) {
			cout << "NO";
			return 0;
		}
		count /= 10;
	}

	cout << "YES";
	return 0;
}