#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T;
string S;

void solve()
{
    cin >> S;
    int N = S.size();
    if((S[N - 1] - '0') % 2 == 0)
    	cout << 0 << '\n';
    else if((S[0] - '0') % 2 == 0)
    	cout << 1 << '\n';
    else
    {
    	for(char c : S)
    	{
    		if((c - '0') % 2 == 0)
    		{
    			cout << 2 << '\n';
    			return;
    		}
    	}
    	cout << -1 << '\n';
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