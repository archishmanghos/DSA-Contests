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
	set<int> haveToErase;
	for(int i = 1; i <= N; i++)
	{
		if(A[i] != A[N - i + 1])
		{
			haveToErase.insert(A[i]);
			haveToErase.insert(A[N - i + 1]);
			break;
		}
	}

	if(haveToErase.size() == 0)
	{
		cout << "YES" << '\n';
		return;
	}

	for(int x: haveToErase)
	{
		vector<int> newArr;
		for(int j = 1; j <= N; j++)
		{
			if(A[j] != x)
				newArr.push_back(A[j]);
		}

		int i = 0, n = newArr.size();
		bool notPossible = false;
		while(i < (n / 2))
		{
			if(newArr[i] != newArr[n - i - 1])
			{
				notPossible = true;
				break;
			}
			i += 1;
		}

		if(!notPossible)
		{
			cout << "YES" << '\n';
			return;
		}
	}

	cout << "NO" << '\n';
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