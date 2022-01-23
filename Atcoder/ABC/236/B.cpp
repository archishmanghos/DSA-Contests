#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;



int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> cnt(N + 2, 0);
    for(int i = 1; i <= 4 * N - 1; i++){
    	int A;
    	cin >> A;
    	cnt[A] += 1;
    }

    for(int i = 1; i <= N; i++){
    	if(cnt[i] < 4){
    		cout << i;
    		return 0;
    	}
    }

    return 0;
}