#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, E, A[mxN];

const int sieveLimit = 1e6 + 5;

bool isPrime[sieveLimit];

void SieveOfEratosthenes()	//Sieve Of Eratosthenes
{
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= sieveLimit; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j < sieveLimit; j += i)
				isPrime[j] = false;
		}
	}
}

void solve()
{
    cin >> N >> E;
    for(int i = 1; i <= N; i++)
    	cin >> A[i];

    vector<int> prefixOne(N + 2, 0), suffixOne(N + 2, 0);
    for(int i = N; i >= 1; i--)
    {
    	if(A[i] == 1)
    		suffixOne[i] += 1;
    	if(i + E <= N)
    		if(A[i + E] == 1)
    			suffixOne[i] += suffixOne[i + E];
    }

    for(int i = 1; i <= N; i++)
    {
    	if(A[i] == 1)
    		prefixOne[i] += 1;
    	if(i - E >= 1)
    		if(A[i - E] == 1)
    			prefixOne[i] += prefixOne[i - E];
    }

    int ans = 0;
    for(int i = 1; i <= N; i++)
    	if(isPrime[A[i]])
    		ans += prefixOne[i] * (suffixOne[i] + 1) + suffixOne[i];

    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SieveOfEratosthenes();

    cin >> T;
    while (T--)
        solve();

    return 0;
}