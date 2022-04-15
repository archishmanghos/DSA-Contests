#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <D:/archishmanghos/Practice/Online_Judges/archiDebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int N, M, startX, startY, A[55][55], t;

bool checkValid(pair<int, int> a){
	return (a.first >= 1 and a.first <= N and a.second >= 1 and a.second <= M);
}

int dp(int index, int timeLeft, int &n, vector<pair<int, int>> &v, vector<vector<int>> &cache){
	if(index >= n or timeLeft == 0){
		return 0;
	}
	if(cache[index][timeLeft] != -1){
		return cache[index][timeLeft];
	}

	int ans;
	if(v[index].second <= timeLeft){
		ans = max(dp(index + 1, timeLeft - v[index].second, n, v, cache) + v[index].first, dp(index + 1, timeLeft, n, v, cache));
	}else{
		ans = dp(index + 1, timeLeft, n, v, cache);
	}

	return cache[index][timeLeft] = ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N >> M >> startX >> startY >> t;
	startX += 1;
	startY += 1;
	queue<pair<int, int>> bfs;

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			cin >> A[i][j];
			if(i == startX and j == startY){
				bfs.push({i, j});
			}
		}
	}

	vector<pair<int, int>> v;
	int maxTime = 0, time = 1, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
	vector<vector<int>> visited(N + 2, vector<int>(M + 2, false));
	visited[startX][startY] = true;

	while(!bfs.empty()){
		int sz = bfs.size();
		for(int i = 1; i <= sz; i++){
			pair<int, int> curCell = bfs.front();
			bfs.pop();
			for(int j = 0; j < 4; j++){
				pair<int, int> newCell = {curCell.first + dx[j], curCell.second + dy[j]};
				if(checkValid(newCell) and !visited[newCell.first][newCell.second]){
					visited[newCell.first][newCell.second] = true;
					v.push_back({A[newCell.first][newCell.second], time * 2 + 1});
					bfs.push(newCell);
				}
			}
		}
		time += 1;
	}

	int n = v.size();
	vector<vector<int>> cache(n + 2, vector<int>(t + 2, -1));
	cout << dp(0, t, n, v, cache);

    return 0;
}