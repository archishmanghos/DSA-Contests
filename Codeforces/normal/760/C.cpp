#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, A[mxN];

void solve()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    	cin >> A[i];
    int gcd1 = -1, gcd2 = -1;
    for(int i = 1; i <= N; i++)
    {
    	if(i & 1)
    		gcd1 = (gcd1 == -1 ? A[i] : __gcd(gcd1, A[i]));
    	else
    		gcd2 = (gcd2 == -1 ? A[i] : __gcd(gcd2, A[i]));
    }

    if(gcd1 == gcd2)
    	cout << 0 << '\n';
    else
    {
    	if(gcd1 != gcd2)
    	{
    		bool allOk = true;
    		for(int i = 1; i <= N; i += 2)
    		{
    			if(A[i] % gcd2 == 0)
    			{
    				allOk = false;
    				break;
    			}
    		}
    		if(allOk)
    			cout << gcd2 << '\n';
    		else
    		{
    			allOk = true;
	    		for(int i = 2; i <= N; i += 2)
	    		{
	    			if(A[i] % gcd1 == 0)
	    			{
	    				allOk = false;
	    				break;
	    			}
	    		}
	    		if(allOk)
	    			cout << gcd1 << '\n';
	    		else
	    			cout << 0 << '\n';
    		}
    	}
    	else
    		cout << 0 << '\n';
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