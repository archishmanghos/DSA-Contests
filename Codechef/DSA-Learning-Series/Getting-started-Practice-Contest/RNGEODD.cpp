#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int L, R;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> L >> R;
    for(int i = L; i <= R; i++)
    {
    	if(i & 1)
    		cout << i << ' ';
    }

    return 0;
}