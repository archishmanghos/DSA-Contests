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

    int ans = N - 1;
    for(int i = 1; i <= N - 1; i++){
    	for(int j = i + 1; j <= N; j++){
    		int toBeChanged = 0;
    		for(int k = i; k >= 1; k--){
    			toBeChanged += (A[i] - A[k]) * (j - i) != (A[j] - A[i]) * (i - k);
    		}
    		for(int k = i; k <= N; k++){
    			toBeChanged += (A[k] - A[i]) * (j - i) != (A[j] - A[i]) * (k - i);
    		}
    		ans = min(ans, toBeChanged);
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