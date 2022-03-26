#include <bits/stdc++.h>

// #ifndef ONLINE_JUDGE

// #include <D:/archishmanghos/Practice/Online_Judges/archiDebug.h>

// #else
// #define debug(x)
// #endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int N;
char A[105][105];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool checkLimits(pair<int, int> x){
	return (x.first >= 1 and x.first <= N and x.second >= 1 and x.second <= N);
}

int bfs(pair<int, int> x, vector<vector<bool>> &visited){
	queue<pair<int, int>> q;
	q.push(x);
	int ans = 0;
	while(!q.empty()){
		pair<int, int> cur = q.front();
		q.pop();
		if(!checkLimits(cur) or A[cur.first][cur.second] == 'N' or visited[cur.first][cur.second]){
			continue;
		}
		ans += 1;
		visited[cur.first][cur.second] = true;
		for(int i = 0; i < 4; i++){
			q.push({cur.first + dx[i], cur.second + dy[i]});
		}
	}

	return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// #ifndef ONLINE_JUDGE
	//     freopen("error.txt", "w", stderr);
	// #endif

	cin >> N;
	vector<vector<bool>> visited(N + 2, vector<bool>(N + 2, false));
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> A[i][j];
		}
	}

	vector<int> ans;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if(A[i][j] == 'C' and !visited[i][j]){
				ans.push_back(bfs({i, j}, visited));
			}
		}
	}

	sort(ans.begin(), ans.end(), greater<int>());
	int player1 = 0, player2 = 0, cur = 1;
	for(int i : ans){
		if(cur){
			player1 += i;
		}else{
			player2 += i;
		}
		cur ^= 1;
	}

	cout << player1 << ' ' << player2;

    return 0;
}