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

int N;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N;

	if(N <= 3)
	{
		cout << "NO";
		return 0;
	}

	cout << "YES" << '\n';
	
	if(N == 4)
	{
		int x = 4;
		for(int i = N - 1; i >= 1; i--)
		{
			cout << x << " * " << i << " = " << (x * i) << '\n';
				x *= i;
		}
	}
	else if(N <= 6)
	{
		int x = N * (N - 1);

		cout << N << " * " << (N - 1) << " = " << x << '\n';

		for(int i = N - 2; i >= 1; i--)
		{
			if(x > 24)
			{
				cout << x << " - " << i << " = " << (x - i) << '\n';
				x -= i;
			}
			else
			{
				cout << x << " + " << i << " = " << (x + i) << '\n';
				x += i;
			}
		}
	}
	else
	{
		if(N & 1)
		{
			for(int i = N; i > 5; i -= 2)
			{
				cout << i << " - " << i - 1 << " = " << 1 << '\n';
				if(i - 2 > 5)
					cout << 1 << " * " << i - 2 << " = " << i - 2 << '\n';
			}

			cout << 1 << " + " << 5 << " = " << 6 << '\n';
			cout << 6 << " * " << 4 << " = " << 24 << '\n';
			cout << 24 << " - " << 3 << " = " << 21 << '\n';
			cout << 21 << " + " << 2 << " = " << 23 << '\n';
			cout << 23 << " + " << 1 << " = " << 24 << '\n';
		}
		else
		{
			for(int i = N; i > 4; i -= 2)
			{
				cout << i << " - " << i - 1 << " = " << 1 << '\n';
				cout << 1 << " * " << i - 2 << " = " << i - 2 << '\n';
			}

			int x = 4;
			for(int i = 3; i >= 1; i--)
			{
				cout << x << " * " << i << " = " << (x * i) << '\n';
					x *= i;
			}
		}
	}

    return 0;
}