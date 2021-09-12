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

int T, N, dist[mxN];
string UV;
string S;
bool visited[mxN];
vector<int> adj[30];

void solve()
{
    cin >> S;
    cin >> N;

    for(int i = 0; i <= 30; i++)
    	adj[i].clear();

    for(int i = 1; i <= N; i++)
    {
    	cin >> UV;
    	char U = UV[0] - 'A';	
    	char V = UV[1] - 'A';
    	adj[U].push_back(V);
    }

    int ans = INF;
    for(char i = 'A'; i <= 'Z'; i++)
    {
    	int total = 0;
    	bool allPossible = true;
    	for(int j = 0; j < S.size(); j++)
    	{
    		int node = S[j] - 'A';
    		memset(visited, false, sizeof(visited));
    		for(int k = 0; k <= 30; k++)
    			dist[k] = INF;
    		int req = i - 'A';

    		if(node == req)
    			continue;

    		queue<int> q;
    		q.push(node);
    		visited[node] = true;
    		dist[node] = 0;

    		while(!q.empty())
    		{
    			int topNode = q.front();
    			q.pop();

    			for(auto it : adj[topNode])
    			{
    				if(!visited[it])
    				{
    					if(dist[it] > (dist[topNode] + 1))
    						dist[it] = dist[topNode] + 1;
    					q.push(it);
    					visited[it] = true;
    				}
    			}
    		}

    		if(dist[req] == INF)
    		{
    			allPossible = false;
    			break;
    		}
    		total += dist[req];
    	}
    	if(allPossible)
    		ans = min(ans, total);
    }

    cout << (ans == INF ? -1 : ans) << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}