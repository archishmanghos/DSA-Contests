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
    int medianX1, medianX2, medianY1, medianY2;
    medianX1 = medianX2 = medianY1 = medianY2 = -1;

    medianX1 = (N + 1) / 2;
    if(N % 2 == 0)
    	medianX2 = medianX1 + 1;

    medianY1 = (M + 1) / 2;
    if(M % 2 == 0)
    	medianY2 = medianY1 + 1;

    int ans = max(abs(medianX1 - 1) + abs(medianY1 - 1), abs(medianX1 - N) + abs(medianY1 - M));
    
    bool visited[N + 2][M + 2];
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({medianX1, medianY1});
    visited[medianX1][medianY1] = true;
    if(medianY2 != -1)
    {
    	q.push({medianX1, medianY2});
    	visited[medianX1][medianY2] = true;
    }
    if(medianX2 != -1)
    {
    	q.push({medianX2, medianY1});
    	visited[medianX2][medianY1] = true;
    }
    if(medianX2 != -1 and medianY2 != -1)
    {
    	q.push({medianX2, medianY2});
    	visited[medianX2][medianY2] = true;
    }

    int cnt = 0;
    while(!q.empty())
    {
    	if(cnt == N *M)
    		break;
    	int sz = q.size();
    	for(int i = 1; i <= sz; i++)
    	{
    		if(cnt == N *M)
    			break;
    		pair<int, int> cur = q.front();
    		q.pop();
    		cnt += 1;
    		cout << ans << ' ';
    		for(int j = 0; j < 4; j++)
    		{
    			int x = cur.first + dx[j];
    			int y = cur.second + dy[j];

    			if(x >= 1 and x <= N and y >= 1 and y <= M and !visited[x][y])
    			{
    				q.push({x, y});
    				visited[x][y] = true;
    			}
    		}
    	}
    	ans += 1;
    }
    cout << '\n';
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