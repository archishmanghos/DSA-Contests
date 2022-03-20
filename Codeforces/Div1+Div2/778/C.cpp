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

int T, N;

void solve()
{
    cin >> N;
    vector<int> A(N);
    queue<int> q;
    int sum = 0;
    unordered_map<int, int> cnt;

    for(int i = 0; i < N; i++){
    	cin >> A[i];
    	cnt[A[i]] += 1;
    	sum += A[i];
    }

    sort(A.begin(), A.end());
    int j = N - 1;
    q.push(sum);
    while(!q.empty()){
    	int sz = q.size(), deleted = 0;
    	multiset<int> added;

    	for(int i = 1; i <= sz; i++){
    		int cur = q.front();
    		q.pop();
    		if(cur == 0){
    			continue;
    		}
    		
    		if(cnt[cur]){
	    		cnt[cur] -= 1;
	    		if(cur == A[j]){
	    			j -= 1;
	    		}
	    		deleted += 1;
	    	}else{
	    		if(cur == 1){
	    			continue;
	    		}
	    		int newCur1 = cur / 2;
	    		int newCur2 = (cur + 1) / 2;
	    		added.insert(newCur1);
	    		added.insert(newCur2);
	    	}
    	}

    	if(j == -1){
    		cout << "YES" << '\n';
    		return;
    	}
    	if(added.size() == 0){
    		break;
    	}

    	if(*added.rbegin() < A[j]){
			cout << "NO" << '\n';
			return;
		}
		auto it = added.rbegin();
		for(it = added.rbegin(); it != added.rend(); it++){
			q.push(*it);
		}
    }

    cout << "NO" << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

    cin >> T;
    while (T--)
        solve();

    return 0;
}