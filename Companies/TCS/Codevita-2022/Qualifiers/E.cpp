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

int N, M, A[50][50];

bool checkValid(pair<int, int> a){
	return (a.first >= 1 and a.first <= N and a.second >= 1 and a.second <= M);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N >> M;
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> path;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			cin >> A[i][j];
			if(A[i][j] == 0){
				path.push({0, {i, j}});
			}
		}
	}

	vector<vector<int>> dist(N + 2, vector<int>(M + 2, INF));
	int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
	int ans = INF;

	while(!path.empty()){
		int weight = path.top().first;
		pair<int, int> curCell = path.top().second;
		path.pop();

		for(int i = 0; i < 8; i++){
			pair<int, int> newCell = {curCell.first + dx[i], curCell.second + dy[i]};
			if(checkValid(newCell)){
				if(dist[newCell.first][newCell.second] > A[newCell.first][newCell.second] + weight){
					dist[newCell.first][newCell.second] = A[newCell.first][newCell.second] + weight;
					path.push({dist[newCell.first][newCell.second], {newCell.first, newCell.second}});
				}
			}else{
				ans = min(ans, weight);
			}
		}
	}

	cout << ans;

    return 0;
}