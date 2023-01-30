#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M; cin >> N >> M;
	string S[N + 2], T[M + 2];
	for (int i = 1; i <= N; i++) cin >> S[i];
	for (int i = 1; i <= M; i++) cin >> T[i];

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		bool flag = false;
		for (int j = 1; j <= M; j++) {
			bool ok = true;
			for (int k = 0; k < 3; k++) ok &= S[i][3 + k] == T[j][k];
			flag |= ok;
			if (flag) break;
		}

		answer += flag;
	}

	cout << answer;
	return 0;
}