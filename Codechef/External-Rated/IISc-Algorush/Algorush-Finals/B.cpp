#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = LLONG_MAX;

int T, N, A;

void solve() {
    
    cin >> N;
    int minDiff = -1, pre;
    cin >> pre;
    if(N == 1){
        if(pre == 0 or pre == 100){
            for(int i = 1; i <= 100; i++) cout << i << ' ';
            cout << '\n';
    		return;
        }else minDiff = pre;
    }
    else if(N == 2 and pre == 0){
    	minDiff = pre;
        cin >> A;
        if(A == 100){
            for(int i = 1; i <= 100; i++) cout << i << ' ';
            cout << '\n';
            return;
    	}
        else{
            minDiff = __gcd(minDiff, A - pre);
    	}
    }
    else{
        minDiff = pre;
        for(int i = 2; i <= N; i++){
            cin >> A;
            if(A != 100){
                if(minDiff == -1) minDiff = A - pre;
                else minDiff = __gcd(minDiff, A - pre);
	    	}
            pre = A;
	    }
    }

    
    set<int> ans;
    for(int i = 1; i * i <= minDiff; i++){
        if(minDiff % i == 0) ans.insert(minDiff / i), ans.insert(i);
    }

    for(int i : ans) cout << i << ' ';
    cout << '\n';
    
}

int32_t main() {
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