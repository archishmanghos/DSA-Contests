#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, P, Q;
string S;

void solve()
{
    cin >> N >> P >> Q >> S;
    int N = S.size();
    pair<int, int> start = {0, 0};
    int x = 1;
    for(int i = 0; i < N; i++)
    {	
    	if(S[i] == '0')
    		x = 1 - x;

    	if(x)
		{
			if(start.first <= P)
				start.first += 1;
			else
				start.first -= 1;
		}
		else
		{
			if(start.second <= Q)
				start.second += 1;
			else
				start.second -= 1;
		}
    }	

    if(start.first == P && start.second == Q)
    {
    	cout << "YES" << '\n';
    	return;
    }

    start = {0, 0};
    x = 0;
    for(int i = 0; i < N; i++)
    {	
    	if(S[i] == '0')
    		x = 1 - x;

    	if(x)
		{
			if(start.first <= P)
				start.first += 1;
			else
				start.first -= 1;
		}
		else
		{
			if(start.second <= Q)
				start.second += 1;
			else
				start.second -= 1;
		}
    }	

    if(start.first == P && start.second == Q)
    	cout << "YES" << '\n';
    else
    	cout << "NO" << '\n';
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