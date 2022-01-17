#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T;
string S;

string integertostring(int x)
{
    string ans = "";
    while (x > 0)
    {
        ans += (x % 10) + '0';
        x /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void solve()
{
    cin >> S;
    int N = S.size();

    bool allSingle = true;
    for(int i = 1; i < N; i++)
    {
    	int a = S[i - 1] - '0';
    	int b = S[i] - '0';
    	allSingle &= (a + b < 10);
    }

    if(allSingle)
    {
    	string ans = "";
    	int x = (S[0] - '0') + (S[1] - '0');
    	string temp = integertostring(x);
    	ans += temp;
    	if(2 < N)
    		ans += S.substr(2);

    	cout << ans << '\n';
    }
    else
    {
    	for(int i = N; i > 0; i--)
    	{
    		int a = S[i - 1] - '0';
    		int b = S[i] - '0';
    		if(a + b >= 10)
    		{
    			string ans = S.substr(0, i - 1);
		    	int x = a + b;
		    	string temp = integertostring(x);
		    	ans += temp;
		    	if(i < N - 1)
		    		ans += S.substr(i + 1);

		    	cout << ans << '\n';
		    	return;
    		}
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