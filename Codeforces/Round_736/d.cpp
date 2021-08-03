// Created: 03-08-2021 10:24:40

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
template <class T, class V> void _print(pair <T, V> p){cerr << "{";_print(p.ff);cerr << ",";_print(p.ss);cerr << "}";}
template <class T> void _print(vector <T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T> void _print(set <T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T> void _print(multiset <T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T, class V> void _print(map <T, V> v){cerr << "[ ";for (auto i : v){_print(i);cerr << " ";}cerr << "]";}

int T, N, A[mxN];

void solve()
{
	cin >> N;
	vector<int> B;

	for(int i = 0; i < N; i++)
		cin >> A[i];

	for(int i = 1; i < N; i++)
		B.push_back(abs(A[i] - A[i - 1]));

	N -= 1;

	int logg[mxN + 1];
	logg[1] = 0;
	for (int i = 2; i <= mxN; i++)
	    logg[i] = logg[i/2] + 1;

	int sparse[N + 5][20];

	for(int i = 0; i < N; i++)
	    sparse[i][0] = B[i];

	for (int j = 1; j <= 18; j++)
	    for (int i = 0; i + (1 << j) <= N; i++)
	        sparse[i][j] = __gcd(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);

	int ans = 0;
	for(int i = 0; i < N; i++)
	{
		int l = i, r = N - 1;
		while(l <= r)
		{
			int mid = (l + r) / 2;
			int L = i, R = mid;
			int gcdd = 0;
			for (int j = 18; j >= 0; j--) 
			{
			    if ((1 << j) <= R - L + 1) 
			    {
			        gcdd = __gcd(gcdd, sparse[L][j]);
			        L += (1 << j);
			    }
			}

			if(gcdd > 1)
			{
				ans = max(ans, (mid - i + 1));
				l = mid + 1;
			}
			else
				r = mid - 1;
		}
	}
	cout << ans + 1 << '\n';
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