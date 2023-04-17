#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int K; cin >> K;
	string S; cin >> S;

	int cnt[26] = {0};
	for (char c : S) cnt[c - 'a']++;
	int gcdd = -1;
	for (int i = 0; i < 26; i++) {
		if (cnt[i]) {
			if (gcdd == -1) gcdd = cnt[i];
			else gcdd = __gcd(gcdd, cnt[i]);
		}
	}

	if (gcdd % K == 0) {
		string repeat = "";
		for (int i = 0; i < 26; i++) {
			if (cnt[i]) {
				for (int j = 1; j <= (cnt[i] / K); j++) {
					repeat += (i + 'a');
				}
			}
		}

		for (int i = 1; i <= K; i++) cout << repeat;
		cout << '\n';
	} else {
		cout << -1 << '\n';
	}
	return 0;
}