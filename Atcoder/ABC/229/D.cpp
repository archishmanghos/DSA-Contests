#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

string S;
int K;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> S >> K;
    int N = S.size();
    int i = 0, j = 0, dot = 0, ans = 0;

    while(j < N)
    {
    	if(S[j] == 'X')
    		j += 1;
    	else
    	{
    		if(dot == K)
    		{
    			ans = max(ans, (j - i));
    			dot -= (S[i] == '.');
    			i += 1;
    			continue;
    		}
    		dot += 1;
    		j += 1;
    	}
    }

    ans = max(ans, j - i);
    cout << ans;

    return 0;
}