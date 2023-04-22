#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N; cin >> N;
	int A[N]; for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);

	int answer = 0;
	for (int i = 0; i < N; i++) answer += abs(A[i] - (i + 1));

	cout << answer;
	return 0;
}