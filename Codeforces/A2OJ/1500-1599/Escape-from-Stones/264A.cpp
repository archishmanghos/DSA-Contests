#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	string S; cin >> S;
	int N = S.size();
	int A[N], l = N - 1, r = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == 'l') A[l--] = i + 1;
		else A[r++] = i + 1;
	}

	for (int i = 0; i < N; i++) cout << A[i] << '\n';
	return 0;
}