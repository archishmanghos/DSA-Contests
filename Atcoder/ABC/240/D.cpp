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

int N, A;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N;
	stack<pair<int, int>> st;
	int ans = 0;

	for(int i = 1; i <= N; i++){
		cin >> A;
		if(st.size() == 0 or st.top().first != A){
			st.push({A, 1});
			ans += 1;
		}else{
			pair<int, int> temp = st.top();
			st.pop();
			ans += 1;
			if(temp.second + 1 == temp.first){
				ans -= A;
			}else{
				temp.second += 1;
				st.push(temp);
			}
		}

		cout << ans << '\n';
	}

    return 0;
}