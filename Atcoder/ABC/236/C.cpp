#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;



int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<string> A(N + 2), B(M + 2);
    set<string> station;

    for(int i = 1; i <= N; i++){
    	cin >> A[i];
    }
    for(int i = 1; i <= M; i++){
    	cin >> B[i];
    	station.insert(B[i]);
    }

    for(int i = 1; i <= N; i++){
    	if(station.find(A[i]) != station.end()){
    		cout << "Yes" << '\n';
    	}
    	else{
    		cout << "No" << '\n';
    	}
    }

    return 0;
}