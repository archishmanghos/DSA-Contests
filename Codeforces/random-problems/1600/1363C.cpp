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

int T, N, X, U, V, visited[mxN], distFromSpecialNode[mxN];
set<int> adj[mxN];

void dfs(int node)
{
	if(visited[node])
		return;
	visited[node] = 1;
	for(auto it : adj[node])
	{
		if(!visited[it])
			distFromSpecialNode[it] = distFromSpecialNode[node] + 1;
		dfs(it);
	}
}

void solve()
{
    cin >> N >> X;
    for(int i = 1; i <= N; i++)
    	adj[i].clear();

    if(N == 1)
    {
    	cout << "Ayush" << '\n';
    	return;
    }
    
	for(int i = 1; i <= N - 1; i++)
	{
		cin >> U >> V;
		adj[U].insert(V);
		adj[V].insert(U);
	}

	memset(distFromSpecialNode, 0, sizeof(distFromSpecialNode));
	memset(visited, 0, sizeof(visited));

	dfs(X);
	int ans = 1;

	while(1)
	{
		vector<int> leafNodes;
		for(int i = 1; i <= N; i++)
		{
			if(adj[i].size() == 1)
			{
				if(i == X)
				{
					cout << (ans & 1 ? "Ayush" : "Ashish") << '\n';
					return;
				}
				leafNodes.push_back(i);
			}
		}

		int lengthOfPath = -INF, leafToBeDeleted = -1;
		for(auto it : leafNodes)
		{
			if(distFromSpecialNode[it] > lengthOfPath)
			{
				lengthOfPath = distFromSpecialNode[it];
				leafToBeDeleted = it;
			}
		}

		for(auto it : adj[leafToBeDeleted])
			adj[it].erase(leafToBeDeleted);
		adj[leafToBeDeleted].clear();
		distFromSpecialNode[leafToBeDeleted] = 0;
		ans += 1;

	}
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