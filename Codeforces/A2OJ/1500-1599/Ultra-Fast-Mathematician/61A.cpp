#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	string A, B; cin >> A >> B;
	for (int i = 0; i < A.size(); i++) cout << (A[i] != B[i]);
	return 0;
}