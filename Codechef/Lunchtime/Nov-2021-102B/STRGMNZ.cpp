#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N;

bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
 
    return true;
}

void solve()
{
    cin >> N;
    if(isPrime(N))
    	cout << N + 1 << '\n';
    else
    {
    	int minFactor;
    	for(int i = 2; i * i <= N; i++)
    	{
    		if(N % i == 0)
    		{
    			minFactor = i;
    			break;
    		}
    	}

    	int ans = N + (N / minFactor);
    	cout << ans << '\n';
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