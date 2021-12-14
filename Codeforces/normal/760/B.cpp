#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N;
string S[mxN];

void solve()
{
    cin >> N;
    for(int i = 1; i <= N - 2; i++)
    	cin >> S[i];

    string ans = S[1];
    bool found = false;
    for(int i = 1; i < N - 2; i++)
    {
    	if(S[i][1] == S[i + 1][0])
    		ans += S[i + 1][1];
    	else
    	{
    		ans += S[i + 1];
    		found = true;
    	}
    }

    if(found)
    	cout << ans << '\n';
    else
    {
    	ans += 'a';
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