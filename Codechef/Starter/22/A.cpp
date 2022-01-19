#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T;

void solve()
{
    int K;
    cin >> K;

   	int prevSum = 0, ans = 0;
   	while(true){
   		int element = K - prevSum;
   		if(element % 2 == 0){
   			ans += 1;
   			prevSum += element / 2;
   		}else{
   			cout << ans << '\n';
   			return;
   		}
   	}
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