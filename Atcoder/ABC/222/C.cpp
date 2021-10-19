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

int N, M;
char A[105][105];

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	if(a.second != b.second)
		return a.second > b.second;
	return a.first < b.first;
}

char rpsgame(char a, char b)
{
	if(a == b)
		return 'd';
	if(a == 'G')
	{
		if(b == 'C')
			return 'w';
		return 'l';
	}
	else if(a == 'C')
	{
		if(b == 'P')
			return 'w';
		return 'l';
	}
	else
	{
		if(b == 'G')
			return 'w';
		return 'l';
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N >> M;
	for(int i = 1; i <= 2 * N; i++)
		for(int j = 1; j <= M; j++)
			cin >> A[i][j];

	set<pair<int, int>, decltype(&cmp)> ans(&cmp);
	for(int i = 1; i <= 2 * N; i++)
		ans.insert({i, 0});

	for(int i = 1; i <= M; i++)
	{
		vector<pair<int, int>> temp;
		for(auto j : ans)
			temp.push_back(j);
		ans.clear();
		for(int j = 0; j < temp.size(); j += 2)
		{
			char outcome = rpsgame(A[temp[j].first][i], A[temp[j + 1].first][i]);
			if(outcome == 'w')
				temp[j].second += 1;
			else if(outcome == 'l')
				temp[j + 1].second += 1;
		}
		for(auto j : temp)
			ans.insert(j);
	}

	for(auto i : ans)
		cout << i.first << '\n';

    return 0;
}