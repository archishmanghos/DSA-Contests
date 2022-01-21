#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T;

void solve()
{
    int N, K, X;
    string S;
    cin >> N >> K >> X >> S;

    X -= 1;
    int cnt = 1;

    vector<pair<char, int>> chunksOfChars;
    for(int i = 0; i < N; i++){
    	int j = i + 1;
    	cnt = 1;
    	while(S[i] == S[j] and j < N){
    		cnt += 1;
    		j += 1;
    	}
    	chunksOfChars.push_back({S[i], cnt});
    	i = j - 1;
    }
    
    vector<int> asteriskChunks;
    for(auto i : chunksOfChars){
    	if(i.first == '*'){
    		asteriskChunks.push_back(i.second * K + 1);
    	}
    }

    int n = asteriskChunks.size();
    vector<int> countBsForEachChunk(n);
    for(int i = n - 1; i >= 0; i--){
    	countBsForEachChunk[i] = X % asteriskChunks[i];
    	X /= asteriskChunks[i];
    }

    int j = n - 1;
    string ans = "";
    for(int i = chunksOfChars.size() - 1; i >= 0; i--){
    	if(chunksOfChars[i].first == '*' and j >= 0){
    		for(int k = 1; k <= countBsForEachChunk[j]; k++){
    			ans += 'b';
    		}
    		j -= 1;
    	}
    	else{
    		for(int k = 1; k <= chunksOfChars[i].second; k++){
    			ans += 'a';
    		}
    	}
    }
    
    while(!ans.empty()){
    	cout << ans.back();
    	ans.pop_back();
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