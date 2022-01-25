#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, L, R, C;

void solve()
{
    cin >> N;
    pair<int, int> maxx = {-INF, INF}, minn = {INF, INF};
    int all = INF;
    
    for(int i = 1; i <= N; i++)
    {
        cin >> L >> R >> C;
        
        if(L < minn.first)
        {
            minn = {L, C};
            all = INF;
        }
        else if(L == minn.first)
            minn.second = min(minn.second, C);

        if(R > maxx.first)
        {
            maxx = {R, C};
            all = INF;
        }
        else if(R == maxx.first)
            maxx.second = min(maxx.second, C);

        if(L == minn.first and R == maxx.first)
            all = min(all, C);
        
        cout << min(minn.second + maxx.second, all) << '\n';
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