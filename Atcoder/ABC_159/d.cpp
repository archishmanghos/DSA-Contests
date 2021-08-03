// Created: 03-08-2021 20:52:05

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

int N, A[mxN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N;
	unordered_map<int, int>  mp, mp1;
	set<int> distinctElements;

	for(int i = 1; i <= N; i++)
	{
		cin >> A[i];
		mp1[A[i]] += 1;
		distinctElements.insert(A[i]);
	}

	int cnt = 0, B[N + 5] = {0};

	for(int i = 1; i <= N; i++)
	{
		cnt += i - 1;
		B[i] = cnt;
	}

	for(int i = 0; i <= N; i++)
		mp[B[i]] = i;

	int ans = 0;
	for(auto it : distinctElements)
		ans += B[mp1[it]];

	for(int i = 1; i <= N; i++)
	{
		int x = mp1[A[i]] - 1;
		int ans1 = ans;
		ans1 -= B[mp1[A[i]]];
		ans1 += B[mp1[A[i]] - 1];
		cout << ans1 << '\n';
	}

    return 0;
}