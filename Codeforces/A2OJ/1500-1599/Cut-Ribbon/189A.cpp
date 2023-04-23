#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, A, B, C; cin >> N >> A >> B >> C;
	int answer = 0;

	for (int i = 0; i <= (N / A); i++) {
		for (int j = 0; j <= (N / B); j++) {
			int sum = i * A + j * B;
			if (sum > N) continue;
			if ((N - sum) % C == 0) {
				answer = max(answer, i + j + (N - sum) / C);
			}
		}
	}

	cout << answer;
	return 0;
}