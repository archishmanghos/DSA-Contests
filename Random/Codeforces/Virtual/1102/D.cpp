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
string S;

string lastChange(int zero, int one, int two)
{
	int equalDistribution = N / 3;
	// 0 = equal distribution
	if(zero == equalDistribution)
	{
		if(one > two)
		{
			for(int i = N - 1; i >= 0; i--)
			{
				if(S[i] == '1')
				{
					if(one == equalDistribution)
						break;
					S[i] = '2';
					two += 1;
					one -= 1;
				}
			}
			return S;
		}
		else
		{
			for(int i = 0; i < N; i++)
			{
				if(S[i] == '2')
				{
					if(one == equalDistribution)
						break;
					S[i] = '1';
					two -= 1;
					one += 1;
				}
			}
			return S;
		}
		return 0;
	}

	// 1 = equal distribution
	if(one == equalDistribution)
	{
		if(zero > two)
		{
			for(int i = N - 1; i >= 0; i--)
			{
				if(S[i] == '0')
				{
					if(zero == equalDistribution)
						break;
					S[i] = '2';
					two += 1;
					zero -= 1;
				}
			}
			return S;
		}
		else
		{
			for(int i = 0; i < N; i++)
			{
				if(S[i] == '2')
				{
					if(zero == equalDistribution)
						break;
					S[i] = '0';
					two -= 1;
					zero += 1;
				}
			}
			return S;
		}
		return 0;
	}

	// 2 = equal distribution
	if(two == equalDistribution)
	{
		if(zero > one)
		{
			for(int i = N - 1; i >= 0; i--)
			{
				if(S[i] == '0')
				{
					if(zero == equalDistribution)
						break;
					S[i] = '1';
					one += 1;
					zero -= 1;
				}
			}
			return S;
		}
		else
		{
			for(int i = 0; i < N; i++)
			{
				if(S[i] == '1')
				{
					if(zero == equalDistribution)
						break;
					S[i] = '0';
					one -= 1;
					zero += 1;
				}
			}
			return S;
		}
		return 0;
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N >> S;

	int A[3] = {0};
	for(char c : S)
		A[(c - '0')] += 1;
	int equalDistribution = N / 3;

	// 0 = 1 = 2
	if(A[0] == A[1] && A[1] == A[2])
	{
		cout << S;
		return 0;
	}

	// any 1 is of equal distribution
	if(A[0] == equalDistribution || A[1] == equalDistribution || A[2] == equalDistribution)
	{
		cout << lastChange(A[0], A[1], A[2]);
		return 0;
	}

	// 0 > 1 and 0 > 2
	if(A[0] >= A[1] && A[0] >= A[2])
	{
		for(int i = N - 1; i >= 0; i--)
		{
			if(A[0] == equalDistribution || A[1] == equalDistribution || A[2] == equalDistribution)
			{
				cout << lastChange(A[0], A[1], A[2]);
				return 0;
			}
			if(S[i] == '0')
			{
				if(A[2] < equalDistribution)
				{
					S[i] = '2';
					A[2] += 1;
					A[0] -= 1;
				}
				else
				{
					S[i] = '1';
					A[1] += 1;
					A[0] -= 1;
				}
			}
		}
		return 0;
	}

	// 1 > 0 and 1 > 2
	if(A[1] >= A[0] && A[1] >= A[2])
	{
		if(A[0] < equalDistribution)
		{
			for(int i = 0; i < N; i++)
			{
				if(A[0] == equalDistribution || A[1] == equalDistribution || A[2] == equalDistribution)
				{
					cout << lastChange(A[0], A[1], A[2]);
					return 0;
				}
				if(S[i] == '1')
				{
					S[i] = '0';
					A[1] -= 1;
					A[0] += 1;
				}
			}
		}
		else
		{
			for(int i = N - 1; i >= 0; i--)
			{
				if(A[0] == equalDistribution || A[1] == equalDistribution || A[2] == equalDistribution)
				{
					cout << lastChange(A[0], A[1], A[2]);
					return 0;
				}
				if(S[i] == '1')
				{
					S[i] = '2';
					A[1] -= 1;
					A[2] += 1;
				}
			}
		}
		
		return 0;
	}
	
	// 2 > 0 and 2 > 1
	if(A[2] >= A[0] && A[2] >= A[1])
	{
		for(int i = 0; i < N; i++)
		{
			if(A[0] == equalDistribution || A[1] == equalDistribution || A[2] == equalDistribution)
			{
				cout << lastChange(A[0], A[1], A[2]);
				return 0;
			}
			if(A[0] < equalDistribution)
			{
				if(S[i] == '2')
				{
					S[i] = '0';
					A[2] -= 1;
					A[0] += 1;
				}
			}
			else
			{
				if(S[i] == '2')
				{
					S[i] = '1';
					A[2] -= 1;
					A[1] += 1;
				}
			}
		}
		return 0;
	}

    return 0;
}