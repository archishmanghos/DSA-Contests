#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, K, A[mxN];

void solve()
{
    cin >> N >> K;
    vector<int> cnt(N + 2, 0);

    for(int i = 1; i <= N; i++)
    	cin >> A[i];

    int total = 0;
    for(int i = 1; i < N; i++)
    {
    	if(A[i] != A[i + 1])
    	{
    		cnt[A[i]] += 1;
    		cnt[A[i + 1]] += 1;
    		total += 1;
    	}
    }
    vector<int> v;
    v.push_back(A[1]);
    for(int i = 2; i <= N; i++)
    {
    	if(A[i] != A[i - 1])
    		v.push_back(A[i]);
    }

    if(v.size() > 2)
    {
    	for(int i = 1; i < v.size() - 1; i++)
    	{
    		if(v[i] != v[i - 1] && v[i] != v[i + 1] && v[i - 1] != v[i + 1])
    			cnt[v[i]] -= 1;
    	}
    }

    for(int i = 1; i <= K; i++)
    	cout << (total - cnt[i]) << ' ';
    cout << '\n';
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