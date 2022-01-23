#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;



int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    cin >> S;
    int A, B;
    cin >> A >> B;
    swap(S[A - 1], S[B - 1]);
    cout << S;

    return 0;
}