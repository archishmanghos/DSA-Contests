#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 1e6 + 5;
const int INF = 1e18 + 7;

int A, X, Y;

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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> Y;
    string ys = integertostring(Y);
    int ns = ys.size();
    queue<int> q;
    X = 1;
    q.push(X);
    int ans = 0;
    vector<int> dist(mxN, mxN);
    dist[X] = 0;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        string s = integertostring(cur * A);
        if(s.size() <= ns)
        {
            int temp = cur * A;
            if(temp <= mxN and dist[temp] > (dist[cur] + 1))
            {
                q.push(temp);
                dist[temp] = dist[cur] + 1;
            }
        }

        if(cur > 10 and (cur % 10) != 0)
        {
        	string tempS = integertostring(cur);
	        string newS = "";
	        newS += tempS[tempS.size() - 1];
	        for(int i = 0; i < tempS.size() - 1; i++)
	            newS += tempS[i];
	        int newT = stringtointeger(newS);

	        if(newS.size() <= ns and newT <= mxN and dist[newT] > (dist[cur] + 1))
	        {
	            q.push(newT);
	            dist[newT] = dist[cur] + 1;
	        }
        }
    }

    cout << (dist[Y] == mxN ? -1 : dist[Y]);

    return 0;
}