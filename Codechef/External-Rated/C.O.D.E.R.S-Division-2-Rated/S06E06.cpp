#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, K;
string S;

void solve()
{
    cin >> S >> K;
    int N = S.size();
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < N; i++)
    	pq.push(S[i] - '0');

    while(K > 0)
    {
    	int top = pq.top();
    	if(top == 9)
    		break;
    	pq.pop();
    	top += 1;
    	K -= 1;
    	pq.push(top);
    }

    int ans = 1;
    while(!pq.empty())
    {
    	ans *= pq.top();
    	pq.pop();
    }

    cout << ans << '\n';
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