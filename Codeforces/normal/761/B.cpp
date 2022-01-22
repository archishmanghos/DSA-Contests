#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T;

void solve()
{
    int N;
    cin >> N;
    if(N % 2 == 0){
    	cout << (N - 3) << ' ' << 2 << ' ' << 1 << '\n';
    }
    else{
    	int mid = (N - 1) / 2;
    	if(mid % 2 == 0){
    		cout << mid - 1 << ' ' << mid + 1 << ' ' << 1 << '\n';
    	}
    	else{
    		cout << mid - 2 << ' ' << mid + 2 << ' ' << 1 << '\n';
    	}
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