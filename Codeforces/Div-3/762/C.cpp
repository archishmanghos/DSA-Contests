#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T;
string A, S;

string removeZeroes(string s)
{
	string ans = "";
	bool dontadd = true;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] != '0')
			dontadd = false;
		if(!dontadd)
			ans += s[i];
	}
	return ans;
}

void solve()
{
    cin >> A >> S;
    int N1 = A.size(), N2 = S.size(), i = 0, j = 0;
    string ans = "";
    reverse(A.begin(), A.end());
    reverse(S.begin(), S.end());

    while(i < N1 && j < N2)
    {
    	int digit1 = (A[i] - '0');
    	int digit2 = (S[j] - '0');

    	if(digit1 <= digit2)
    	{
    		ans += ((digit2 - digit1) + '0');
    		i += 1;
    		j += 1;
    	}
    	else
    	{
    		j += 1;
    		digit2 += (S[j] - '0') * 10;
    		if(digit2 - digit1 >= 0 && digit2 - digit1 <= 9)
    		{
    			ans += ((digit2 - digit1) + '0');
	    		i += 1;
	    		j += 1;
    		}
    		else
    		{
    			cout << -1 << '\n';
    			return;
    		}
    	}
    }

    if(i == N1)
    {
    	while(j < N2)
    	{
    		ans += S[j];
    		j += 1;
    	}

    	reverse(ans.begin(), ans.end());
    	ans = removeZeroes(ans);
    	cout << ans << '\n';
    }
    else
    	cout << -1 << '\n';
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