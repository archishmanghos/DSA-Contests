#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int N, A;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int pre = -INF, ans;
    for(int i = 1; i <= N; i++)
    {
    	cin >> A;
    	if(A > pre)
    		pre = A;
    	else 
    	{
    		if(pre != INF)
    		{
    			ans = pre;
    			pre = INF;
    		}
    	}
    }

    if(pre != INF)
	{
		ans = pre;
		pre = INF;
	}

    cout << ans;

    return 0;
}