#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

	auto ip = unique(A.begin(), A.begin() + N);
	A.resize(distance(A.begin(), ip));

	N = A.size();

	if (N <= 2) {
		cout << N << '\n';
		return;
	}

	vector<int> v;
	v.push_back(A[0]);
	v.push_back(A[1]);

	int answer = 0;
	bool dec = A[1] < A[0], inc = A[1] > A[0];
	for (int i = 2; i < N; i++) {
		if (A[i] > v.back()) {
			if (inc) {
				v.pop_back();
				v.push_back(A[i]);
			} else {
				int x = v.back();
				v.pop_back();
				v.pop_back();
				++answer;
				v.push_back(x);
				v.push_back(A[i]);
				inc = true;
				dec = false;
			}
		} else {
			if (dec) {
				v.pop_back();
				v.push_back(A[i]);
			} else {
				int x = v.back();
				v.pop_back();
				v.pop_back();
				++answer;
				v.push_back(x);
				v.push_back(A[i]);
				inc = false;
				dec = true;
			}
		}
	}

	answer += 2;
	cout << answer << '\n';
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	while (T--)
		solve();
	return 0;
}
