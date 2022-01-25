#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, A[10];

void solve()
{
    for(int i = 1; i <= 7; i++)
    	cin >> A[i];

    int cnt = 0;
    for(int i = 1; i <= 6; i++)
    {
    	if(cnt < 2 && A[i] <= A[7])
		{
			A[7] -= A[i];
			cout << A[i] << ' ';
			cnt += 1;
		}
		else
		{
			if(A[i] == A[7])
			{
				cout << A[i] << '\n';
				return;
			}
		}
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