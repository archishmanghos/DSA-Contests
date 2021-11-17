#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

#ifndef ONLINE_JUDGE
#define debugarr(x,i,j) cerr << #x <<" "; _print(x,i,j); cerr << endl;
#else
#define debugarr(x)
#endif

void _print(int t){cerr << t;}
void _print(string t){cerr << t;}
void _print(bool t){cerr << t;}
void _print(char t){cerr << t;}
void _print(long double t){cerr << t;}
void _print(double t){cerr << t;}
void _print(unsigned long long t){cerr << t;}
template <class T> void _print(T arr[], int i, int j){cerr << "[ " ;for ( int k = i; k <= j; k++) cerr << arr[k] << ", " ;cerr << "]\n";}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p){cerr << "{";_print(p.first);cerr << ",";_print(p.second);cerr << "}";}
template <class T> void _print(vector <T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T> void _print(set <T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T> void _print(multiset <T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T, class V> void _print(map <T, V> v){cerr << "[ ";for (auto i : v){_print(i);cerr << " ";}cerr << "]";}

int T, N, K;

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
			for (int j = i * i; j <= sieveLimit; j += i)
				isPrime[j] = false;
		}
	}
}

void solve()
{
    cin >> N >> K;
    int cnt = 1;
    set<int> allPrimes;
    allPrimes.insert(1);
    for(int i = N; i > (N / 2); i--)
    {
    	if(isPrime[i])
    	{
    		cnt += 1;
    		allPrimes.insert(i);
    	}
    }

    for(int i = cnt; i >= 1; i--)
    {
    	if(i == K)
    	{
    		cout << "YES" << '\n';
    		int j = 0;
    		for(int k : allPrimes)
    		{
    			cout << k << ' ';
    			j += 1;
    			if(j == i)
    				break;
    		}
    		cout << '\n';
    		return;
    	}
    	if((N - i) == K)
    	{
    		cout << "YES" << '\n';
    		int j = 0;
    		for(int k = 2; k <= N; k++)
    		{
    			if(!allPrimes.count(k))
    			{
    				cout << k << ' ';
    				j += 1;
    			}
    			if(j == N - i)
    				break;
    		}
    		if(j < (N - i))
    		{
    			for(int k : allPrimes)
	    		{
	    			cout << k << ' ';
	    			j += 1;
	    			if(j == N - i)
	    				break;
	    		}
    		}
    		cout << '\n';
    		return;
    	}
    }

    cout << "NO" << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    SieveOfEratosthenes();
    cin >> T;
    while (T--)
        solve();

    return 0;
}