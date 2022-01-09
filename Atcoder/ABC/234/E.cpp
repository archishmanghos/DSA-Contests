#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int X, finalAns;
vector<int> num;

int stringtointeger(string x)
{
    int ans = 0, j = 1;
 
    for (int i = x.size() - 1; i >= 0; i--)
    {
        ans += (x[i] - '0') * j;
        j *= 10;
    }
 
    return ans;
}

void dp(string s, int prevDigitLarger, int adiff)
{
	if(s.size() > 18)
		return;

	int x = stringtointeger(s);
	if(x >= X)
		finalAns = min(finalAns, x);
	int curPos = s.size();
	int prevDigit = (curPos > 0 ? (s[curPos - 1] - '0') : -1);
	int start = (prevDigitLarger ? 0 : num[curPos]);

	for(int i = start; i <= 9; i++)
	{
		string temp = s;
		if(curPos == 0)
		{
			temp += (i + '0');
			if(prevDigitLarger or i > num[curPos])
				dp(temp, 1, 0);
			else
				dp(temp, 0, 0);
		}
		else if(curPos == 1)
		{
			temp += (i + '0');
			if(prevDigitLarger or i > num[curPos])
				dp(temp, 1, i - prevDigit);
			else
				dp(temp, 0, i - prevDigit);
		}
		else
		{
			if(i - prevDigit == adiff)
			{
				temp += (i + '0');
				if(prevDigitLarger or i > num[curPos])
					dp(temp, 1, adiff);
				else
					dp(temp, 0, adiff);
			}
		}
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> X;
    int X1 = X;
    while(X1 > 0)
    {
        num.push_back(X1 % 10);
        X1 /= 10;
    }
    reverse(num.begin(), num.end());
    finalAns = INF;
    dp("", 0, 0);
    cout << finalAns;

    return 0;
}