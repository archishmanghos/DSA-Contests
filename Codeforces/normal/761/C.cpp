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
    for(int i = 1; i <= N; i++){
    	cin >> A[i];
    }

    set<int> remainders;
    for(int i = 1; i <= N; i++){
    	remainders.insert(i);
    }

    sort(A.begin() + 1, A.begin() + N + 1);
    int ans = 0;
    for(int i = 1; i <= N; i++){
    	if(remainders.find(A[i]) == remainders.end()){
    		int maxRems = (A[i] - 1) / 2;
    		int lowestRem = *remainders.begin();
    		if(lowestRem <= maxRems){
    			ans += 1;
    			remainders.erase(lowestRem);
    		}
    		else{
    			cout << -1 << '\n';
    			return;
    		}
    	}
    	else{
    		remainders.erase(A[i]);
    	}
    }

    cout << ans << '\n';
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