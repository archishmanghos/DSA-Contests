#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int N, K, A;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    bool ans = false;
    for(int i = 1; i <= N; i++)
    {
    	cin >> A;
    	ans |= A == K;
    }

    cout << (ans ? 1 : -1);

    return 0;
}