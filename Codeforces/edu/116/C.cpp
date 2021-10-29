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

int T, N, K, X;
vector<int> A(15);

void solve()
{
    cin >> N >> K;
    int z = 0;
    for(int i = 1; i <= N; i++)
    {
    	cin >> X;
    	A[i] = (i == 1 ? 1 : A[i - 1]);
    	while(z < X)
    	{
    		A[i] *= 10;
    		z += 1;
    	}
    }

    int coinDiff = 0;
   	for(int i = 1; i < N; i++)
   	{
   		coinDiff += (A[i + 1] / A[i]) - 1;
   		if(coinDiff > K)
   		{
   			int ans = 0;
   			for(int j = 1; j < i; j++)
   			{
   				ans += A[j] * ((A[j + 1] / A[j]) - 1);
   				K -= (A[j + 1] / A[j]) - 1;
   			}
   			ans += (K + 1) * A[i];
   			cout << ans << '\n';
   			return;
   		}
   	}

   	int ans = 0;
   	for(int j = 1; j < N; j++)
	{
		ans += A[j] * ((A[j + 1] / A[j]) - 1);
		K -= (A[j + 1] / A[j]) - 1;
	}

	ans += (K + 1) * A[N];
	cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> T;
    while (T--)
        solve();

    return 0;
}