#include <bits/stdc++.h>
#define int long long
using namespace std;

string S;
int cache[2000][5][5];

int getInt(char ch) {
	return (ch == 'P' ? 0 : ch == 'R' ? 1 : 2);
}

int dp(int idx, int firstCh, int preCh) {
	if (idx == S.size()) return 0;
	int &answer = cache[idx][firstCh][preCh];
	if (answer != -1) return answer;

	answer = 1e9;
	int curCh = getInt(S[idx]), nextCh = (idx + 1 == S.size() ? firstCh : getInt(S[idx + 1]));


	if (preCh != curCh and curCh != nextCh) {
		answer = dp(idx + 1, (idx == 0 ? curCh : firstCh), curCh);
	} else {

		if (preCh == curCh) {
			if (idx == 0) {
				answer = dp(idx + 1, curCh, curCh);
				for (int i = 0; i <= 2; i++) {
					if (i != curCh) {
						answer = min(answer, dp(idx + 1, i, i) + 1);
					}
				}
			} else {
				for (int i = 0; i <= 2; i++) {
					if (i != curCh) {
						answer = min(answer, dp(idx + 1, firstCh, i) + 1);
					}
				}
			}
		}

		if (curCh == nextCh) {
			if (idx == S.size() - 1) {
				for (int i = 0; i <= 2; i++) {
					if (i != curCh) {
						answer = min(answer, dp(idx + 1, firstCh, i) + 1);
					}
				}
			} else {
				if (preCh != curCh) answer = dp(idx + 1, (idx == 0 ? curCh : firstCh), curCh);
				for (int i = 0; i <= 2; i++) {
					if (i != curCh) {
						answer = min(answer, dp(idx + 1, (idx == 0 ? i : firstCh), i) + 1);
					}
				}
			}
		}


	}

	return answer;
}

void solve() {
	cin >> S;
	memset(cache, -1, sizeof(cache));
	cout << dp(0, 0, getInt(S.back())) << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}