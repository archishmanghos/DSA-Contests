#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, H, A[105];

void solve()
{
    cin >> N >> H;
    for(int i = 1; i <= N; i++)
    	cin >> A[i];

    int maxGap = 0, power = 0;
    for(int i = 2; i <= N; i++)
    {
    	power += A[i] - A[i - 1];
    	maxGap = max(maxGap, A[i] - A[i - 1]);
    }
    power += maxGap;

    if(power <= H)
    {
    	cout << maxGap + (H - power) << '\n';
    	return;
    }
    else
    {
    	int low = 0, high = maxGap;
    	while(low <= high)
    	{
    		int mid = low + (high - low) / 2;
    		int power = 0;
    		for(int i = 2; i <= N; i++)
    			power += min(mid, A[i] - A[i - 1]);
    		power += mid;
    		if(power < H)
    			low = mid + 1;
    		else if(power > H)
    			high = mid - 1;
    		else
    		{
    			cout << mid << '\n';
    			return;
    		}
    	}

    	cout << low << '\n';
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