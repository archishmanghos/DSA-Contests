#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, M;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve()
{
    cin >> N >> M;
    vector<vector<char>> A(N + 2, vector<char>(M + 2));
    queue<pair<int, int>> q;

    for(int i = 1; i <= N; i++)
    {
    	for(int j = 1; j <= M; j++)
    	{
    		cin >> A[i][j];
    		if(A[i][j] == 'L')
    			q.push({i, j});
    	}
    }

    while(!q.empty())
    {
    	pair<int, int> curCell = q.front();
    	q.pop();
    	
    	for(int i = 0; i < 4; i++)
    	{
    		if(A[curCell.first + dx[i]][curCell.second + dy[i]] == '.')
    		{
    			int noBlocks = 0;
    			for(int j = 0; j < 4; j++)
    			{
    				if((curCell.first + dx[i] + dx[j] >= 1 && curCell.first + dx[i] + dx[j] <= N) && (curCell.second + dy[i] + dy[j] >= 1 && curCell.second + dy[i] + dy[j] <= M))
    					noBlocks += A[curCell.first + dx[i] + dx[j]][curCell.second + dy[i] + dy[j]] == '.';
    			}

    			if(noBlocks <= 1)
    			{
    				A[curCell.first + dx[i]][curCell.second + dy[i]] = '+';
    				q.push({curCell.first + dx[i], curCell.second + dy[i]});
    			}
    		}
    	}
    }

    for(int i = 1; i <= N; i++)
    {
    	for(int j = 1; j <= M; j++)
    		cout << A[i][j];
    	cout << '\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
        solve();

    return 0;
}