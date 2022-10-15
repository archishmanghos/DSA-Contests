#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

void solve() {
	int stoneR, houseR; cin >> stoneR >> houseR;
	int N; cin >> N;
	vector<vector<int>> red(N, vector<int>(2));
	for (int i = 0; i < N; i++) {
		cin >> red[i][0] >> red[i][1];
	}

	int M; cin >> M;
	vector<vector<int>> yellow(M, vector<int>(2));
	for (int i = 0; i < M; i++) {
		cin >> yellow[i][0] >> yellow[i][1];
	}

	vector<vector<int>> distanceToCircle(N + M, vector<int>(3));
	for (int i = 0; i < N; i++) {
		distanceToCircle[i][0] = red[i][0] * red[i][0] + red[i][1] * red[i][1];
		distanceToCircle[i][1] = i;
		distanceToCircle[i][2] = 0;
	}

	for (int i = 0; i < M; i++) {
		distanceToCircle[N + i][0] = yellow[i][0] * yellow[i][0] + yellow[i][1] * yellow[i][1];
		distanceToCircle[N + i][1] = i;
		distanceToCircle[N + i][2] = 1;
	}

	sort(distanceToCircle.begin(), distanceToCircle.end());
	int redScore = 0, yellowScore = 0, distToOverCome = (houseR + stoneR) * (houseR + stoneR);
	for (int i = 0; i < N + M; i++) {
		if (distanceToCircle[i][2] == 1 and redScore > 0) {
			break;
		}
		if (distanceToCircle[i][2] == 0 and yellowScore > 0) {
			break;
		}

		if (distanceToCircle[i][0] > distToOverCome) {
			break;
		}

		if (distanceToCircle[i][2] == 0) {
			redScore += 1;
		} else {
			yellowScore += 1;
		}
	}

	cout << redScore << ' ' << yellowScore << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}