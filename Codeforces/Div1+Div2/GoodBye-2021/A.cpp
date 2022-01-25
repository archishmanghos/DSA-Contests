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
    vector<int> A(N + 2);
    map<int, int> mp;
    for(int i = 1; i <= N; i++){
    	cin >> A[i];
    	if(mp[A[i]] > 0){
    		A[i] = -A[i];
    	}
    	mp[A[i]] += 1;
    }

    mp.clear();
    for(int i = 1; i <= N; i++){
    	mp[A[i]] += 1;
    }

    cout << mp.size() << '\n';
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