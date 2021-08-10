// Created: 08-08-2021 17:36:30

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

int H, W, N, X, Y;

bool sortbyfirs(const pair<pair<int, int>,int> &a, const pair<pair<int, int>,int> &b)
{
	return a.first.first < b.first.first;
}

bool sortbysec(const pair<pair<int, int>,int> &a, const pair<pair<int, int>,int> &b)
{
	return a.first.second < b.first.second;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> H >> W >> N;
	vector<pair<pair<int, int>, int>> v;

	for(int i = 1; i <= N; i++)
	{
		cin >> X >> Y;
		v.push_back({{X, Y}, i});
	}

	sort(v.begin(), v.end(),sortbyfirs);

	int prev = -1, j = 1;
	for(int i = 0; i < v.size(); i++)
	{
		if(v[i].first.first == prev)
		{
			prev = v[i].first.first;
			v[i].first.first = j - 1;
		}
		else
		{
			prev = v[i].first.first;
			v[i].first.first = j;
			j += 1;
		}
	}

	sort(v.begin(), v.end(), sortbysec);

	prev = -1, j = 1;
	for(int i = 0; i < v.size(); i++)
	{
		if(v[i].first.second == prev)
		{
			prev = v[i].first.second;
			v[i].first.second = j - 1;
		}
		else
		{
			prev = v[i].first.second;
			v[i].first.second = j;
			j += 1;
		}
	}

	vector<pair<int, int>> ans(N + 5);
	for(auto it : v)
		ans[it.second] = it.first;

	for(int i = 1; i <= N; i++)
		cout << ans[i].first << ' ' << ans[i].second << '\n';

    return 0;
}