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

int T, N, weight[mxN], U, V, leafWeights[mxN];
string leafPath[mxN];
vector<int> adj[mxN];
vector<pair<int, int>> nodes, leafs, bridges;
bool visited[mxN];

void dfs(int node, int parent)
{
    if(visited[node])
        return;

    visited[node] = true;
    leafWeights[node] = leafWeights[parent] + weight[node];
    leafPath[node] = leafPath[parent] + (char)(node + '0');

    if(adj[node].size() == 1)
    {
        if(adj[node][0] == parent)
        {
            leafs.push_back({node, leafWeights[node]});
            return;
        }
    }

    for(auto it : adj[node])
    {
        if(it != parent)
            dfs(it, node);
    }

    nodes.push_back({node, leafWeights[node]});
}

void solve()
{
    cin >> N;

    for(int i = 1; i <= N; i++)
        adj[i].clear();
    memset(weight, 0, sizeof(weight));

    for(int i = 1; i <= N; i++)
        cin >> weight[i];

    for(int i = 1; i <= N - 1; i++)
    {
        cin >> U >> V;
        adj[U].push_back(V);
        adj[V].push_back(U);
    }

    memset(visited, false, sizeof(visited));
    memset(leafWeights, 0, sizeof(leafWeights));
    leafs.clear();
    nodes.clear();
    bridges.clear();
    for(int i = 1; i <= N; i++)
        leafPath[i] = "";
    
    leafs.push_back({1, weight[1]});
    dfs(1, 0);

    int ans = 0;
    if(leafs.size() > 1)
    {
        for(int i = 0; i < leafs.size(); i++)
        {
            for(int j = i + 1; j < leafs.size(); j++)
            {
                int cost = weight[1];
                string compare, compared;
                if(leafPath[leafs[i].first].size() > leafPath[leafs[j].first].size())
                {
                    compare = leafPath[leafs[i].first];
                    compared = leafPath[leafs[j].first];
                }
                else
                {
                    compare = leafPath[leafs[j].first];
                    compared = leafPath[leafs[i].first];
                }

                for(int k = 1; k < compare.size(); k++)
                {
                    int node1 = compare[k] - '0';
                    if(k < compared.size())
                    {
                        int node2 = compared[k] - '0';
                        if(compare[k] == compared[k])
                        {
                            cost = 0;
                            break;
                        }
                        else
                            cost += weight[node1] + weight[node2];
                    }
                    else
                        cost += weight[node1];
                }
                ans = max(ans, cost);
            }

        }
    }
    else
    {
        string compare = leafPath[leafs[0].first];
        for(int k = 0; k < compare.size(); k++)
        {
            int node1 = compare[k] - '0';
            ans += weight[node1];
        }
    }

    cout << ans << '\n';
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