#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, A;

void solve() {
    set<int> s;
    cin >> N;
    int sum = 0;
    for(int i = 1; i <= N; i++){
    	cin >> A;
    	sum += A;
    	s.insert(A);
    }
    debug(s)
    if(sum % N == 0){
    	cout << (s.find(sum / N) != s.end() ? "YES" : "NO") << '\n';
    }else cout << "NO" << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

    cin >> T;
    while (T--)
        solve();

    return 0;
}