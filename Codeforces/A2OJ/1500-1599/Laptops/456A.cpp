#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N; cin >> N;
	map<int, int> laptop;
	for (int i = 0; i < N; i++) {
		int A, B; cin >> A >> B;
		if (laptop.find(A) != laptop.end()) laptop[A] = min(laptop[A], B);
		else laptop[A] = B;
	}

	int pre = -1;
	for (auto it : laptop) {
		if (it.second < pre) {
			cout << "Happy Alex";
			return 0;
		}
		pre = it.second;
	}

	cout << "Poor Alex";
	return 0;
}