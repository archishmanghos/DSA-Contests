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

int N, M, U, V, dist[mxN], paths[mxN], visited[mxN];
vector<int> adj[mxN];

const int mod = 1e9 + 7;

int add(int a, int b, int p = mod)
{
    int c = a + b;
    if (c >= p)
        c -= p;
    return c;
}

int sub(int a, int b, int p = mod)
{
    int c = a - b;
    if (c < 0)
        c += p;
    return c;
}

int mul(int a, int b, int p = mod)
{
    return (a * (int)1 * b) % p;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif

    cin >> N >> M;
    for(int i = 1; i <= M; i++)
    {
        cin >> U >> V;
        adj[U].push_back(V);
        adj[V].push_back(U);
    }

    for(int i = 1; i <= N; i++)
        dist[i] = INF;

    memset(paths, 0, sizeof(paths));
    memset(visited, 0, sizeof(visited));

    dist[1] = 0;
    paths[1] = 1;

    queue<int> q;
    q.push(1);

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        debug(cur)
        for(auto it : adj[cur])
        {
            if(!visited[it])
            {
                q.push(it);
                visited[it] = 1;
            }

            if(dist[it] > (dist[cur] + 1))
            {
                dist[it] = dist[cur] + 1;
                paths[it] = paths[cur];
            }
            else if(dist[it] == dist[cur] + 1)
                paths[it] = add(paths[it], paths[cur]);
        }
    }

    debug(dist[4])
    cout << (dist[N] == 1 ? 1 : paths[N]);

    return 0;
}

//24-07-2021 18:47:11