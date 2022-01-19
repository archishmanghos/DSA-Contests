#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T;

void solve()
{
    int N, M;
    cin >> N >> M;
    pair<int, int> robot, dirtyCell;
    cin >> robot.first >> robot.second >> dirtyCell.first >> dirtyCell.second;

    int ans = 0, dr = 1, dc = 1;
    while(robot.first != dirtyCell.first and robot.second != dirtyCell.second){
    	if(robot.first + dr < 1 or robot.first + dr > N)
    		dr = -dr;
    	if(robot.second + dc < 1 or robot.second + dc > M)
    		dc = -dc;
    	ans += 1;
    	robot.first += dr;
    	robot.second += dc;
    }

    cout << ans << '\n';
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