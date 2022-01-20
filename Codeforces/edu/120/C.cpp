#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e9 + 7;

int T;

void solve()
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N + 2), prefSum(N + 2, 0);
    
    int sum = 0;
    for(int i = 1; i <= N; i++){
    	cin >> A[i];
    }
    sort(A.begin() + 1, A.begin() + N + 1);

    for(int i = 1; i <= N; i++){
        sum += A[i];
        prefSum[i] = sum;
    }
    
    int ans = max((int)0, A[1] - (K - (sum - prefSum[1])));
    for(int i = 2; i <= N; i++){
    	int sumLeftToBeDistributed = K - (prefSum[i - 1] - prefSum[1]);

        int terms = N - i + 2;
    	if(sumLeftToBeDistributed >= 0){
    		sumLeftToBeDistributed /= terms;
    	}else{
            sumLeftToBeDistributed = (sumLeftToBeDistributed - terms + 1) / terms;
    	}

    	int steps = max((int)0, A[1] - sumLeftToBeDistributed);
    	steps += N - i + 1;
    	ans = min(ans, steps);
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