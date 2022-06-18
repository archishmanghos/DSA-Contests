#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 1e3 + 5;
const int INF = 1e18 + 7;

int T, N, M, A[mxN][mxN];

bool dfs(int indexX, int indexY, int countOne, int countMinusOne, vector<vector<int>> &cntOne, vector<vector<int>> &cntMinusOne, vector<vector<bool>> &visited){
	if(indexX >= N or indexY >= M) {
		if(indexY == M - 1 or indexX == N - 1) return countOne == 0 and countMinusOne == 0;
		return false;
	}
	if(visited[indexX][indexY]) return false;
 
	visited[indexX][indexY] = true;
	bool ans = false;
	if(cntOne[indexX][indexY] >= countOne and cntMinusOne[indexX][indexY] >= countMinusOne){
		countOne -= A[indexX][indexY] == 1;
		countMinusOne -= A[indexX][indexY] == -1;
		ans = dfs(indexX + 1, indexY, countOne, countMinusOne, cntOne, cntMinusOne, visited) | dfs(indexX, indexY + 1, countOne, countMinusOne, cntOne, cntMinusOne, visited);
	}
 
	return ans;
}

void solve() {
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++) cin >> A[i][j];
	}

	int pathLength = N + M - 1;
	if(pathLength & 1) cout << "NO" << '\n';
	else{
		vector<vector<int>> cntOne(N, vector<int>(M, 0));
		vector<vector<int>> cntMinusOne(N, vector<int>(M, 0));
		vector<vector<bool>> visited(N, vector<bool>(M, false));

		for(int i = N - 1; i >= 0; i--){
			for(int j = M - 1; j >= 0; j--){
				int right = (j < M - 1 ? cntOne[i][j + 1] : 0);
				int left = (i < N - 1 ? cntOne[i + 1][j] : 0);
 
				cntOne[i][j] = A[i][j] == 1 ? max(left, right) + 1 : max(left, right);
 
				right = (j < M - 1 ? cntMinusOne[i][j + 1] : 0);
				left = (i < N - 1 ? cntMinusOne[i + 1][j] : 0);
 
				cntMinusOne[i][j] = A[i][j] == -1 ? max(left, right) + 1 : max(left, right);
			}
		}

		cout << (dfs(0LL, 0LL, pathLength / 2, pathLength / 2, cntOne, cntMinusOne, visited) ? "YES" : "NO") << '\n';
	}
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