#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T;

void solve()
{
    int A, B, C;
    cin >> A >> B >> C;

    if(A + B == C or A + C == B or B + C == A){
    	cout << "YES" << '\n';
    }
    else if(A == B and (C % 2 == 0)){
    	cout << "YES" << '\n';
    }
    else if(A == C and (B % 2 == 0)){
    	cout << "YES" << '\n';
    }
    else if(B == C and (A % 2 == 0)){
    	cout << "YES" << '\n';
    }
    else{
    	cout << "NO" << '\n';
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