#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, A[mxN];

void solve()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    	cin >> A[i];

    if(N == 1)
    {
    	cout << A[1] << '\n';
    	return;
    }

    sort(A + 1, A + N + 1, greater<int>());
    bool zero = false;
    for(int i = 1; i <= N; i++)
    	zero |= A[i] == 0;
    if(zero)
    {
    	int cnt = 0, maxx = 0, front = 0;
    	for(int i = 1; i <= N; i++)
    	{
    		if(A[i] == 0)
    			break;
    		front += 1;
    	}
    	for(int i = 1; i <= N; i++)
    	{
    		if(A[i] == 0)
    		{
    			maxx = max(maxx, cnt);
    			cnt = 0;
    		}
    		else
    			cnt += 1;
    	}

    	maxx = max(maxx, (cnt + front));
    	cout << maxx << '\n';
    }
    else
    {
    	int minn = INF, pos, lastPos;
    	for(int i = 1; i <= N; i++)
    	{
    		if(A[i] < minn)
    		{
    			minn = A[i];
    			pos = i;
    		}
    	}
    	for(int i = N; i >= 1; i--)
    	{
    		if(A[i] == minn)
    		{
    			lastPos = i;
    			break;
    		}
    	}

    	pos += (N - lastPos);
    	int ans = minn * N + (pos - 1);
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