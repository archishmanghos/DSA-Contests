#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int N, K, P;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 1; i <= N; i++)
    {
    	cin >> P;
    	pq.push(P);
    	if(pq.size() > K)
    		pq.pop();
    	if(i >= K)
    		cout << pq.top() << '\n';
    }

    return 0;
}