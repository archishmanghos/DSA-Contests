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

    bool ans = true;
    ans &= (A[0] + A[1]) > A[2];
    ans &= (A[1] + A[2]) > A[0];
    ans &= (A[0] + A[2]) > A[1];

    if(ans)
    {
    	if(A[0] == A[2])
    		cout << 1;
    	else if(A[0] == A[1] || A[1] == A[2])
    		cout << 2;
    	else
    		cout << 3;
    }
    else
    	cout << -1;

    return 0;
}