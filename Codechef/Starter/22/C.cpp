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
    if(N == 2){
    	cout << "NO" << '\n';
    }else if(N % 2 == 0){
    	cout << "YES" << '\n';
    	vector<int> ans(N + 2);
    	int i = 1, j;
    	for(j = 3; j <= N; j++){
    		ans[j] = i;
    		i += 2;
    		if(i == N - 1){
    			break;
    		}
    	}
    	ans[1] = i;
    	i = N;
    	ans[2] = i;
    	i -= 2;
    	j += 1;
    	for(; j <= N; j++){
    		ans[j] = i;
    		i -= 2;
    		if(i == 0){
    			break;
    		}
    	}
    	for(int i = 1; i <= N; i++){
    		cout << ans[i] << ' ';
    	}
    	cout << '\n';
    }else{
    	cout << "YES" << "\n";
    	int i = N, j = 1, index = 1, turn = 0;
    	vector<int> ans(N + 2, -1);

    	while(j < i){
    		if(!turn){
    			ans[index] = i;
    			ans[N - index + 1] = i - 1;
    			i -= 2;
    		}else{
    			ans[index] = j;
    			ans[N - index + 1] = j + 1;
    			j += 2;
    		}
    		turn ^= 1;
    		index += 1;
    	}

    	ans[N / 2 + 1] = j;
    	for(int i = 1; i <= N; i++){
    		cout << ans[i] << ' ';
    	}
    	cout << '\n';
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