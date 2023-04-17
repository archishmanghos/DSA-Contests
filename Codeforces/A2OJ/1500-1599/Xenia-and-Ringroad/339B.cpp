#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M, A, curHouse = 1, answer = 0; cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A;
		if (curHouse <= A) answer += A - curHouse;
		else answer += (N - curHouse) + A;
		curHouse = A;
	}

	cout << answer;
	return 0;
}