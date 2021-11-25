#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int A[3];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 3; i++)
    	cin >> A[i];
    sort(A, A + 3);

    cout << A[1];

    return 0;
}