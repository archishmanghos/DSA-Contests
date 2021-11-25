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
    set<int> ans;

    for(int i = 1; i * i <= N; i++)
    {
    	if(N % i == 0)
    	{
    		ans.insert(i);
    		ans.insert(N / i);
    	}
    }

    cout << ans.size() << '\n';
    for(int i : ans)
    	cout << i << ' ';

    return 0;
}