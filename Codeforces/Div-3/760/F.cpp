#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

string integertobinary(int x)
{
	string ans = "";
	while(x > 0)
	{
	    ans += (x % 2) + '0';
	    x >>= 1;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

string removeZeroes(string s)
{
	string ans = "";
	bool dontadd = true;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '1')
			dontadd = false;
		if(!dontadd)
			ans += s[i];
	}
	return ans;
}

int X, Y;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> X >> Y;
    string S1 = integertobinary(X), S2 = integertobinary(Y);
    map<string, bool> visited;

    queue<string> q;
    q.push(S1);
    while(!q.empty())
    {
    	string curnum = q.front();
    	q.pop();
    	if(curnum == S2)
    	{
    		cout << "YES";
    		return 0;
    	}
    	if(visited[curnum])
    		continue;
    	visited[curnum] = true;

    	string num1, num2;
    	if(curnum.size() < S2.size())
    		num1= curnum + '1';
    	num2 = curnum + '0';
    	reverse(num1.begin(), num1.end());
    	reverse(num2.begin(), num2.end());
    	num1 = removeZeroes(num1);
    	num2 = removeZeroes(num2);

    	if(num1.size() > 0)
    		q.push(num1);	
    	if(num2.size() > 0)
    		q.push(num2);
    }

    cout << "NO";

    return 0;
}