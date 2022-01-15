#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int N, Q, A, X, K;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;

    map<int, vector<int>> mp;
    for(int i = 1; i <= N; i++)
    {
    	cin >> A;
    	mp[A].push_back(i);
    }

    while(Q--)
    {
    	cin >> X >> K;
    	if(mp.find(X) != mp.end())
    	{
    		if(mp[X].size() >= K)
    			cout << mp[X][K - 1] << '\n';
    		else
    			cout << -1 << '\n';
    	}
    	else
    		cout << -1 << '\n';
    }

    return 0;
}