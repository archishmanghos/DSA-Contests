#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
// #include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int fun(vector<int> &a, int m) {
	int n = a.size();
	sort(a.begin(), a.end());

	int low = 0, high = a[n - 1] - a[0], answer = -1;
	while (low <= high) {
		int mid = low + (high - low) / 2;

		int pre = 0, possible = 1;
		for (int i = 1; i < n; i++) {
			if (a[i] - a[pre] > mid) {
				if (i - pre < m) {
					possible = 0;
					break;
				}
				pre = i;
			}
		}

		possible &= (n - pre >= m);
		if (possible) {
			answer = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	return answer;
}

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M; cin >> N >> M;
	vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

	cout << fun(A, M);
	return 0;
}