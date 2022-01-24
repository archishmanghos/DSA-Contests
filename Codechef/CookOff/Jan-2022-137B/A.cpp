#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T;

void solve()
{
    int N;
    char a = 'a';
    cin >> N;
    for(int i = 1; i <= N; i++){
    	cout << a;
    	if(a == 'z'){
    		a = 'a';
    	}
    	else{
    		a += 1;
    	}
    }
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