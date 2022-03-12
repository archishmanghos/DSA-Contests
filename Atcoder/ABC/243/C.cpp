#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <D:/archishmanghos/Practice/Online_Judges/archiDebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int N;
vector<pair<pair<int, int>, int>> A(mxN);
string S;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> A[i].first.first >> A[i].first.second;
		A[i].second = i - 1;
	}

	auto cmp = [](pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b){
		if(a.first.second != b.first.second){
			return a.first.second < b.first.second;
		}
		return a.first.first < b.first.first;
	};

	sort(A.begin() + 1, A.begin() + N + 1, cmp);
	map<int, char> mp;
	cin >> S;
	for(int i = 1; i <= N; i++){
		if(mp.find(A[i].first.second) != mp.end()){
			if(mp[A[i].first.second] != S[A[i].second]){
				cout << "Yes";
				return 0;
			}
		}else{
			if(S[A[i].second] == 'R'){
				mp[A[i].first.second] = S[A[i].second];
			}
		}
	}

	cout << "No";

    return 0;
}