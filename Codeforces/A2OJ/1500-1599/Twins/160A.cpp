#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N; cin >> N;
	int A[N]; for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);
	int totalSum = accumulate(A, A + N, 0), curSum = 0, answer = 0;
	for (int i = N - 1; i >= 0; i--) {
		curSum += A[i];
		totalSum -= A[i];
		answer++;
		if (curSum > totalSum) break;
	}

	cout << answer;
	return 0;
}