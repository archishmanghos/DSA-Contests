#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, A[mxN];

void solve()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> A[i];

	map<int, int> present;
	vector<vector<int>> perm(N + 2);
	for(int i = 1; i <= N; i++)
	{
		while(A[i] > 0)
		{
			if(A[i] <= N)
				perm[i].push_back(A[i]);
			A[i] >>= 1;
		}
	}

	for(int i = 1; i <= N; i++)
	{
		bool done = false;
		for(int j : perm[i])
		{
			if(!present[j] and !done)
			{
				bool later = false;
				for(int k = i + 1; k <= N; k++)
				{
					for(int l : perm[k])
					{
						if(l == j)
						{
							later = true;
							break;
						}
					}
					if(later)
						break;
				}
				if(later)
					continue;
				done = true;
				present[j] = 1;
			}
		}
		if(!done)
		{
			for(int j : perm[i])
			{
				if(!present[j])
					present[j] = 1;
			}
		}
	}

	for(int i = 1; i <= N; i++)
	{
		if(!present[i])
		{
			cout << "NO" << '\n';
			return;
		}
	}

	cout << "YES" << '\n';
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