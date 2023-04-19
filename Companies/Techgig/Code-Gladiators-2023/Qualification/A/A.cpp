#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, X; cin >> N >> X;
	int A[N]; for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);

	if (A[N - X - 1] == A[N - X]) cout << -1;
	else cout << A[N - X];
	return 0;
}