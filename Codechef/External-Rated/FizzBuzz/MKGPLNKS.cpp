#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N;
string S;

void solve()
{
    cin >> N >> S;
    int i = 0, ans1 = 0;
    bool continues = false;
    string S1 = S;

    // change to black
    while(i < N)
    {
    	if(S1[i] == 'W')
    	{
    		S1[i] = 'B';
    		if(!continues)
    		{
    			ans1 += 1;
    			continues = true;
    		}
    	}
    	else
    		continues = false;
    	i += 1;
    }

    i = 0, S1 = S;
    int ans2 = 0;
    continues = false;

    // change to white
    while(i < N)
    {
    	if(S1[i] == 'B')
    	{
    		S1[i] = 'W';
    		if(!continues)
    		{
    			ans2 += 1;
    			continues = true;
    		}
    	}
    	else
    		continues = false;
    	i += 1;
    }

    cout << min(ans1, ans2) << '\n';
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