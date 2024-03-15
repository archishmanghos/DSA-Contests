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

	int N; cin >> N;
	int P[N], P1[N];
	for (int i = 0; i < N; i++) {
		cin >> P[i];
		P1[i] = P[i];
	}
	int extra; cin >> extra;

	sort(P, P + N, greater<int>());
	sort(P1, P1 + N);

	int i = 0, j = N - 1, answer1 = 0;

	while (i <= j) {
		answer1 += P[i++];
		j -= extra;
	}

	i = 0, j = N - 1;
	int answer2 = 0;
	while (i <= j) {
		answer2 += P1[i++];
		j -= extra;
	}

	cout << answer2 << '\n' << answer1;
	return 0;
}