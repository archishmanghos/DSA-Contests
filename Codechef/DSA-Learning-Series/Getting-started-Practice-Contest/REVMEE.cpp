#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int N, A[mxN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N; i++)
    	cin >> A[i];

    for(int i = N; i >= 1; i--)
    	cout << A[i] << ' ';

    return 0;
}