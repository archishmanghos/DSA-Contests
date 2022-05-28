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

int N, T;
string S;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> N;
    map<string, int> bestScore;
    vector<pair<int, int>> originalStrings;
    for(int i = 1; i <= N; i++){
    	cin >> S >> T;
    	if(bestScore.find(S) == bestScore.end()){
    		bestScore[S] = T;
    		originalStrings.push_back({T, i});
    	}
    }

    sort(originalStrings.begin(), originalStrings.end(),[](pair<int,int> &a,pair<int,int> &b){
    	if(a.first != b.first) return a.first > b.first;
    	return a.second < b.second;
    });

    cout << originalStrings[0].second;

    return 0;
}