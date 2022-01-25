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
    vector<pair<int, pair<int, int>>> A(N + 2);
    set<pair<int, int>> S;

    auto comp = [&](const pair<int, pair<int, int>> a, const pair<int, pair<int, int>> b)->bool{
    	return a.first > b.first;
    };

    for(int i = 1; i <= N; i++){
    	cin >> A[i].second.first >> A[i].second.second;
    	A[i].first = A[i].second.second - A[i].second.first + 1;
    	S.insert(A[i].second);
    }

    sort(A.begin() + 1, A.begin() + N + 1, comp);
    for(int i = 1; i <= N; i++){
    	int l = A[i].second.first;
    	int r = A[i].second.second;

    	cout << l << ' ' << r << ' ';

    	if(l == r){
    		cout << l << '\n';
    		continue;
    	}

    	for(int j = l; j <= r ; j++){
    		if(j == l or j == r){
    			pair<int, int> range;
    			if(j == l){
    				range = {j + 1, r};
    			}else{
    				range = {l, j - 1};
    			}
    			if(S.find(range) != S.end()){
    				cout << j << '\n';
    				break;
    			}
    		}else{
    			pair<int, int> range1, range2;
    			range1 = {l, j - 1};
    			range2 = {j + 1, r};
    			if(S.find(range1) != S.end() and S.find(range2) != S.end()){
    				cout << j << '\n';
    				break;
    			}
    		}
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