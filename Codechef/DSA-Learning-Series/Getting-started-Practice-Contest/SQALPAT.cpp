#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int N;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 1; i <= N; i++)
    {
    	if(i & 1)
    	{
    		for(int j = 1; j <= 5; j++)
    			cout << (i - 1) * 5 + j << ' ';
    	}
    	else
    	{
    		for(int j = 5; j >= 1; j--)
    			cout << (i - 1) * 5 + j << ' ';
    	}
    	cout << '\n';
    }

    return 0;
}