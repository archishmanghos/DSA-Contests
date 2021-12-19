#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int H, W;
char A[105][105];
int dx[2] = {1, 0};
int dy[2] = {0, 1};

bool isValid(pair<int, int> p)
{
	if(p.first < 1 || p.first > H)
		return false;
	if(p.second < 1 || p.second > W)
		return false;
	return A[p.first][p.second] == '.';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> H >> W;
    for(int i = 1; i <= H; i++)
    	for(int j = 1; j <= W; j++)
    		cin >> A[i][j];

    vector<vector<bool>> visited(H + 2, vector<bool> (W + 2, false));
    vector<vector<int>> dist(H + 2, vector<int> (W + 2, INF));
    queue<pair<int, int>> q;
    q.push({1, 1});
    dist[1][1] = 1;
    int ans = 1;

    while(!q.empty())
    {
    	pair<int, int> curCell = q.front();
    	q.pop();
    	if(visited[curCell.first][curCell.second])
    		continue;
    	visited[curCell.first][curCell.second] = true;

    	for(int i = 0; i < 2; i++)
    	{
    		pair<int, int> cell = {curCell.first + dx[i], curCell.second + dy[i]};
    		if(isValid(cell))
    		{
    			dist[cell.first][cell.second] = min(dist[cell.first][cell.second], dist[curCell.first][curCell.second] + 1);
    			ans = max(ans, dist[cell.first][cell.second]);
    			q.push(cell);
    		}
    	}
    }

    cout << ans;

    return 0;
}