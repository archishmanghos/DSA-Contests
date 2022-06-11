#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e5 + 7;



int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    vector<int> v = {1, 2, 3, 4};
    int ans = 1;
    for(int i = 1; i <= 4; i++) ans *= i;
    cout << ans << '\n';
    do{
    	cout << 4 << '\n';
    	for(int i : v){
    		cout << i << ' ';
    	}
    	cout << '\n';
    } while(next_permutation(v.begin(), v.end()));


    return 0;
}