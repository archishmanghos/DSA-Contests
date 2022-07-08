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

int T;

void solve() {
    
    vector<vector<int>>a, b;
    int n;
    cin >> n;
    int sizea[n];

    for(int i = 0; i < n; i++)cin >> sizea[i];

    for(int i = 0; i < n; i++){
        vector<int>temp;
    	int val;
        for(int j = 0; j < sizea[i]; j++){
            cin >> val;
            temp.push_back(val);
    	}

        sort(temp.begin(), temp.end());
        a.push_back(temp);
    }

    int m;
    cin >> m;

    int sizeb[m];

    for(int i = 0; i < m; i++)cin >> sizeb[i];

    for(int i = 0; i < m; i++){
        vector<int>temp;
        int val;

        for(int j = 0; j < sizeb[i]; j++){
            cin >> val;
            temp.push_back(val);
    	}

        sort(temp.begin(), temp.end());
        b.push_back(temp);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if(n == m){
        for(int i = 0; i < n; i++){
            if(a[i].size() != b[i].size()){    cout << "No\n";    return;}
            for(int j = 0; j < a[i].size(); j++){
                if(a[i][j] != b[i][j]){    cout << "No\n";    return;}
    		}
    	}

        cout << "Yes\n";
    }
    else cout << "No\n";
    
    
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