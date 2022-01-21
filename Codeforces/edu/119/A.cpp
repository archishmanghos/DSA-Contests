#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T;

void solve()
{
    string S;
    cin >> S;

    int cntN = 0;
    for(int i = 0; i < S.size(); i++){
        cntN += S[i] == 'N';
        if(cntN > 1){
            cout << "YES" << '\n';
            return;
        }
    }

    cout << (cntN ? "NO" : "YES") << '\n';
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