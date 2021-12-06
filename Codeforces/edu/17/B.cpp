#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 3e5 + 5;
const int INF = 1e18 + 7;

int A, B, C, M;
vector<pair<int, string>> V(mxN);

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> B >> C >> M;
    for(int i = 1; i <= M; i++)
    	cin >> V[i].first >> V[i].second;

    sort(V.begin() + 1, V.begin() + M + 1);
    int computers = 0, cost = 0;

    for(int i = 1; i <= M; i++)
    {
    	if(V[i].second == "USB")
    	{
    		if(A > 0)
    		{
    			computers += 1;
    			cost += V[i].first;
    			A -= 1;
    		}
    		else if(C > 0)
    		{
    			computers += 1;
    			cost += V[i].first;
    			C -= 1;
    		}
    	}
    	else
    	{
    		if(B > 0)
    		{
    			computers += 1;
    			cost += V[i].first;
    			B -= 1;
    		}
    		else if(C > 0)
    		{
    			computers += 1;
    			cost += V[i].first;
    			C -= 1;
    		}
    	}
    }

    cout << computers << ' ' << cost;

    return 0;
}