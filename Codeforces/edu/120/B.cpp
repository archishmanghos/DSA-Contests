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
    vector<int> P(N + 2);
    for(int i = 0; i < N; i++){
    	cin >> P[i];
    }

    string S;
    cin >> S;

    vector<pair<int, int>> flop, hit;
    for(int i = 0; i < N; i++){
    	if(S[i] == '1'){
    		hit.push_back({P[i], i});
    	}
    	else{
    		flop.push_back({P[i], i});
    	}
    }

    sort(flop.begin(), flop.end());
    sort(hit.begin(), hit.end());

    int j = 1;
    for(int i = 0; i < flop.size(); i++){
    	P[flop[i].second] = j;
    	j += 1;
    }

    for(int i = 0; i < hit.size(); i++){
    	P[hit[i].second] = j;
    	j += 1;
    }

    for(int i = 0; i < N; i++){
    	cout << P[i] << ' ';
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