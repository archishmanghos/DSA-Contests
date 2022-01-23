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
    vector<int> A(N + 2), cnt(N + 2, 0);

    for(int i = 1; i <= N; i++){
    	cin >> A[i];
    	cnt[A[i]] += 1;
    }

    int nowMex;
    for(int i = 0; i <= N + 1; i++){
    	if(cnt[i] == 0){
    		nowMex = i;
    		break;
    	}
    }

    vector<int> lastOccurence(N + 2, -1), ans;
    int nextMex = nowMex, ongoingMex = 0, end = 0;

    for(int i = 1; i <= N; i++){

    	if((A[i] < nowMex) and lastOccurence[A[i]] <= end){
    		ongoingMex += 1;
    	}

    	cnt[A[i]] -= 1;
    	if(cnt[A[i]] == 0){
    		nextMex = min(A[i], nextMex);
    	}

    	lastOccurence[A[i]] = i;
    	if(ongoingMex == nowMex){
    		ans.push_back(ongoingMex);
    		ongoingMex = 0;
    		end = i;
    		nowMex = nextMex;
    	}
    	
    }

    cout << ans.size() << '\n';
    for(int i : ans)
    	cout << i << ' ';
    cout << '\n';

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