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

int N, M1, M2, U, V;
int parent1[mxN], parent2[mxN], rank1[mxN], rank2[mxN];

void makeSet()
{
	for(int i = 1; i <= N; i++)
	{
		parent1[i] = i;
		parent2[i] = i;
		rank1[i] = 0;
		rank2[i] = 0;
	}
}

int findParentMocha(int x)
{
	if(x == parent1[x])
		return x;

	return parent1[x] = findParentMocha(parent1[x]);
}

int findParentDiana(int x)
{
	if(x == parent2[x])
		return x;

	return parent2[x] = findParentDiana(parent2[x]);
}

void unionOfEdgesMocha(int u, int v)
{
	int parentU = findParentMocha(u);
	int parentV = findParentMocha(v);

	if(rank1[parentU] < rank1[parentV])
		parent1[parentU] = parentV;
	else if(rank1[parentU] > rank1[parentV])
		parent1[parentV] = parentU;
	else
	{
		parent1[parentU] = parentV;
		rank1[parentV] += 1;
	}
}

void unionOfEdgesDiana(int u, int v)
{
	int parentU = findParentDiana(u);
	int parentV = findParentDiana(v);

	if(rank2[parentU] < rank2[parentV])
		parent2[parentU] = parentV;
	else if(rank2[parentU] > rank2[parentV])
		parent2[parentV] = parentU;
	else
	{
		parent2[parentU] = parentV;
		rank2[parentV] += 1;
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N >> M1 >> M2;

	makeSet();

	set<pair<int, int>> edges, newEdges;
	for(int i = 1; i <= M1; i++)
	{
		cin >> U >> V;
		unionOfEdgesMocha(U, V);
		edges.insert({U, V});
		edges.insert({V, U});
	}

	for(int i = 1; i <= M2; i++)
	{
		cin >> U >> V;
		unionOfEdgesDiana(U, V);
		edges.insert({U, V});
		edges.insert({V, U});
	}

	vector<pair<int, int>> restEdges;
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			if(i != j && !edges.count({i, j}) &&!edges.count({j, i}))
				restEdges.push_back({i, j});
		}
	}

	vector<pair<int, int>> ans;
	for(auto i : restEdges)
	{
		if(findParentMocha(i.first) != findParentMocha(i.second))
		{
			if(findParentDiana(i.first) != findParentDiana(i.second))
			{
				ans.push_back(i);
				unionOfEdgesDiana(i.first, i.second);
				unionOfEdgesMocha(i.first, i.second);
			}
		}
	}

	cout << ans.size() << '\n';
	for(auto it : ans)
		cout << it.first << ' ' << it.second << '\n';

    return 0;
}