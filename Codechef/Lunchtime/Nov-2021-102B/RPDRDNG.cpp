#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, A[mxN];

void solve()
{
    cin >> N;
    map<int, int> cnt;
    for(int i = 1; i <= 2 * N; i++)
    {
    	cin >> A[i];
    	cnt[A[i]] += 1;
    }

    sort(A + 1, A + (2 * N) + 1);
    vector<int> unique;
    unique.push_back(A[1]);
    for(int i = 2; i <= 2 * N; i++)
    {
    	if(A[i] != A[i - 1])
    		unique.push_back(A[i]);
    }

    if(unique.size() != N)
    {
    	cout << -1 << '\n';
    	return;
    }

    if(N == 1)
    {
    	if(cnt[unique[0]] == 2)
    		cout << unique[0] << '\n';
    	else
    		cout << -1 << '\n';
    	return;
    }

    for(int i = 0; i < N; i++)
	{
		if(i == (N - 1) / 2)
		{
			if(cnt[unique[i]] != 3)
			{
				cout << -1 << '\n';
				return;
			}
		}
		else if(i == N - 1)
		{
			if(cnt[unique[i]] != 1)
			{
				cout << -1 << '\n';
				return;
			}
		}
		else
		{
			if(cnt[unique[i]] != 2)
			{
				cout << -1 << '\n';
				return;
			}
		}
	}
	for(int i : unique)
		cout << i << ' ';
	cout << '\n';

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