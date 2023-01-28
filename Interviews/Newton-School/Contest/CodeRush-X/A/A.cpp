#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int A[4]; cin >> A[1] >> A[2] >> A[3];
	for (int i = 1; i <= 2; i++) {
		for (int j = i + 1; j <= 3; j++) {
			if ((A[i] + A[j]) > 0 and (A[i] + A[j]) % 2 == 0) {
				cout << "YES" << '\n';
				return 0;
			}
		}
	}

	cout << "NO" << '\n';
	return 0;
}