#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e9 + 7;

int T, N;
map<int, int> mp;

void solve()
{
    cin >> N;
    int ans = 0;
    for(auto it : mp)
    {
    	if(it.first > N)
    		break;
    	ans += 1;
    }

    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 1; i <= 100000; i++)
    {
    	if(i * i > INF)
    		break;
    	mp[i * i] = 1;
    }
    for(int i = 1; i <= 10000; i++)
    {
    	if(i *i * i > INF)
    		break;
    	mp[i * i * i] = 1;
    }

    cin >> T;
    while (T--)
        solve();

    return 0;
}