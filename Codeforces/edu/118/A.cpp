#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, P1, P2;
string X1, X2;

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
    cin >> X1 >> P1 >> X2 >> P2;
    int N1 = X1.size(), N2 = X2.size();
    if((N1 + P1) > (N2 + P2))
    	cout << '>' << '\n';
    else if((N1 + P1) < (N2 + P2))
    	cout << '<' << '\n';
    else
    {
    	int minn = min(P1, P2);
    	P1 -= minn;
    	P2 -= minn;

    	int low = 1, high = max((N2 + P2), (N1 + P1));
    	while(low <= high)
    	{
    		int mid = low + (high - low) / 2;
    		string temp1, temp2;
    		int l = min(mid, N1);
    		temp1 += X1.substr(0, l);
    		int rem = mid - l;
    		for(int j = 1; j <= rem; j++)
    			temp1 += '0';
 
    		l = min(mid, N2);
    		temp2 += X2.substr(0, l);
    		rem = mid - l;
    		for(int j = 1; j <= rem; j++)
    			temp2 += '0';
 
    		if(temp1 == temp2)
    			low = mid + 1;
    		else if(temp1 < temp2)
    		{
    			cout << '<' << '\n';
    			return;
    		}
    		else
    		{
    			cout << '>' << '\n';
    			return;
    		}
    	}
    	cout << '=' << '\n';
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