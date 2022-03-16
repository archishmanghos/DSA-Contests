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

int T, N, M;
pair<int, int> x, y;

bool check(pair<int, int> curCell){
	if(curCell.first >= 1 and curCell.first <= N and curCell.second >= 1 and curCell.second <= M){
		return true;
	}
	return false;
}

void solve()
{
    cin >> N >> M;
    cin >> x.first >> x.second >> y.first >> y.second;

    int ans[N + 2][M + 2];
    memset(ans, 0, sizeof(ans));
    ans[y.first][y.second] = 2;

    queue<pair<int, int>> q;
    q.push(x);

    while(!q.empty()){
    	pair<int, int> curCell = q.front();
    	q.pop();
    	if(ans[curCell.first][curCell.second] == 0){
    		ans[curCell.first][curCell.second] = 1;
    		pair<int, int> x = {curCell.first + 1, curCell.second + 1};
    		if(check(x)){
    			q.push(x);
    		}
    		x = {curCell.first + 1, curCell.second - 1};
    		if(check(x)){
    			q.push(x);
    		}
    		x = {curCell.first - 1, curCell.second + 1};
    		if(check(x)){
    			q.push(x);
    		}
    		x = {curCell.first - 1, curCell.second - 1};
    		if(check(x)){
    			q.push(x);
    		}
    	}
    }

    ans[y.first][y.second] = 0;
    q.push(y);

    while(!q.empty()){
    	pair<int, int> curCell = q.front();
    	q.pop();
    	debug(curCell)
    	if(ans[curCell.first][curCell.second] == 0){
    		ans[curCell.first][curCell.second] = 2;
    		pair<int, int> x = {curCell.first + 1, curCell.second + 1};
    		if(check(x)){
    			q.push(x);
    		}
    		x = {curCell.first + 1, curCell.second - 1};
    		if(check(x)){
    			q.push(x);
    		}
    		x = {curCell.first - 1, curCell.second + 1};
    		if(check(x)){
    			q.push(x);
    		}
    		x = {curCell.first - 1, curCell.second - 1};
    		if(check(x)){
    			q.push(x);
    		}
    	}
    }

    for(int i = 1; i <= N; i++){
    	for(int j = 1; j <= M; j++){
    		cout << (!ans[i][j] ? 3 : ans[i][j]) << ' ';
    	}
    	cout << '\n';
    }
}

int32_t main()
{
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