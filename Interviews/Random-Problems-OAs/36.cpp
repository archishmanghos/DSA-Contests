#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include </home/archishman/DSA/DSA-Contests/archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M; cin >> N;
	int A[N], B[N];
	for (int i = 0; i < N; i++) cin >> A[i];
	cin >> M;
	for (int i = 0; i < N; i++) cin >> B[i];

	int answer = 0;
	for (int i = 0; i < N; i++) answer = max(answer, A[i] * 5 + B[i] * 2);
	cout << answer;
	return 0;
}