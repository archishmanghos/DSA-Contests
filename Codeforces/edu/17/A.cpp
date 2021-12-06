#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int N, K;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    int cnt = 0;
    for(int i = 1; i * i <= N; i++)
    {
    	if(N % i == 0)
    	{
    		cnt += 1;
    		cnt += ((N / i) != i);
    	}
    }

    if(cnt >= K)
    {
    	int counter = 0;
    	for(int i = 1; i * i <= N; i++)
    	{
    		if(N % i == 0)
    		{
    			counter += 1;
    			if(counter == K)
    			{
    				cout << i;
    				return 0;
    			}
    			else if(cnt - counter + 1 == K)
    			{
    				cout << N / i;
    				return 0;
    			}
    		}
    	}
    }

    cout << -1;
    return 0;
}