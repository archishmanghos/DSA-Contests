#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, M, A;

void solve() {
	cin >> N >> M;
	pair<int, int> cell;
	int maxx = -INF;

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++){
			cin >> A;
			if(A > maxx){
				maxx = A;
				cell = {i, j};
			}
		}
	}

	int maxRow = min(cell.first - 1, N - cell.first);
	int maxCol = min(cell.second - 1, M - cell.second);

	cout << (N - maxRow) *(M - maxCol) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> T;
    while (T--)
        solve();

    return 0;
}