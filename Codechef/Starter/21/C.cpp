#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, M;

int PF(int n)
{
	int ans = 0;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			ans += 1;
			while (n % i == 0)
				n /= i;
		}
	}
	if(n > 1 and ans > 0)
		ans += 1;
	return ans;
}

void solve()
{
    cin >> N >> M;

    if(M == 1)
    {
    	cout << 0 << '\n';
    	return;
    }

    int pf = PF(M);
    while(pf)
    {
    	if(N % pf == 0)
    	{
    		cout << pf << '\n';
    		return;
    	}
    	pf -= 1;
    }

    cout << 1 << '\n';
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