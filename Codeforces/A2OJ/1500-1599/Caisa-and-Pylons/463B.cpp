#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N; cin >> N;
	int H[N]; for (int i = 0; i < N; i++) cin >> H[i];

	int answer = 0, pre = 0;
	for (int i = 0; i < N; i++) {
		if (H[i] > pre) {
			answer += H[i] - pre;
			pre = H[i];
		}
	}
	cout << answer;
	return 0;
}