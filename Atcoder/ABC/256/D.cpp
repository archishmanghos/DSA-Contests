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

int N;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> N;
    vector<pair<int, int>> v(N);
    for(int i = 0; i < N; i++) {
    	cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    int start = v[0].first, end = v[0].second;
    vector<pair<int, int>> ans;

    for(int i = 1; i < N; i++){
    	if(v[i].first <= end) end = max(end, v[i].second);
    	else {
    		ans.push_back({start, end});
    		start = v[i].first, end = v[i].second;
    	}
    }

    ans.push_back({start, end});
    for(auto i : ans) cout << i.first << ' ' << i.second << '\n';

    return 0;
}