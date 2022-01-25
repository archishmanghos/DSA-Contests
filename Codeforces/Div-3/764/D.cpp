#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, K;
string S;

void solve()
{
    cin >> N >> K >> S;
    vector<int> cnt(30, 0);

    for(char c : S)
    	cnt[c - 'a'] += 1;

    int even = K, odd = 0, ans = 0;
    while(1)
    {
    	int one = 0;
    	int notOne = 0;
    	for(int i = 0; i < 26; i++)
    	{
    		notOne += cnt[i] / 2;
    		one += cnt[i] % 2 == 1;
    	}

    	if(notOne >= K)
    	{
    		ans += 2;
    		int minus = K;
    		for(int i = 0; i < 26; i++)
    		{
    			if(cnt[i] and minus)
    			{
    				int m = min(minus, cnt[i] / 2);
    				minus -= m;
    				cnt[i] -= m * 2;
    			}
    		}
    	}
    	else if(notOne + one >= K)
    	{
    		if(notOne >= odd)
    		{
    			int m = notOne;
    			int x = min(K - notOne, one);
    			even -= x;
    			odd += x;
    			ans += 1;

    			for(int i = 0; i < 26; i++)
	    		{
	    			if(cnt[i] and m)
	    			{
	    				int y = min(m, cnt[i] / 2);
	    				m -= y;
	    				cnt[i] -= y * 2;
	    			}
	    		}

	    		for(int i = 0; i < 26; i++)
	    		{
	    			if(cnt[i] and x)
	    			{
	    				int y = min(x, cnt[i] / 2);
	    				x -= y;
	    				cnt[i] -= y;
	    			}
	    		}
    		}
    		else
    		{
    			cout << max(ans, (int)1) << '\n';
    			return;
    		}
    	}
    	else if(notOne * 2 >= K)
		{
			ans += 1;
			cout << max(ans, (int)1) << '\n';
			return;
		}
		else if(notOne * 2 + one >= K)
		{
			ans += 1;
			cout << max(ans, (int)1) << '\n';
			return;
		}
    	else
    	{
    		cout << max(ans, (int)1) << '\n';
    		return;
    	}

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