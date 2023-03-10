#include <bits/stdc++.h>
#define int long long

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N; std::cin >> N;
	std::string S; std::cin >> S;
	std::deque<int> dq;
	dq.push_back(N);

	while (N--) {
		if (S[N] == 'R') dq.push_front(N);
		else dq.push_back(N);
	}

	while (!dq.empty()) {
		std::cout << dq.front() << ' ';
		dq.pop_front();
	}
	return 0;
}