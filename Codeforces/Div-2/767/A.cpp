#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T;

void solve()
{
    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> A(N + 2);

    for(int i = 1; i <= N; i++){
    	cin >> A[i].first;
    }
    for(int i = 1; i <= N; i++){
    	cin >> A[i].second;
    }

    sort(A.begin() + 1, A.begin() + N + 1);

    for(int i = 1; i <= N; i++){
    	if(A[i].first <= K){
    		K += A[i].second;
    	}
    	else{
    		break;
    	}
    }

    cout << K << '\n';
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