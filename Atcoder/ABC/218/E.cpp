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

int N, M, U, V, W;
int parent[mxN], rankOfEdge[mxN];

struct node
{
    int u, v, wt;
};

bool myComp(const node &a, const node &b)
{
    return a.wt < b.wt;
}

void makeSet()
{
    for(int i = 1; i <= N; i++)
    {
        parent[i] = i;
        rankOfEdge[i] = 0;
    }
}

int findParent(int x)
{
    if(x == parent[x])
        return x;

    return parent[x] = findParent(parent[x]);
}

void unionOfEdges(int u, int v)
{
    int parentU = findParent(u);
    int parentV = findParent(v);

    if(rankOfEdge[parentU] < rankOfEdge[parentV])
        parent[parentU] = parentV;
    else if(rankOfEdge[parentU] > rankOfEdge[parentV])
        parent[parentV] = parentU;
    else
    {
        parent[parentU] = parentV;
        rankOfEdge[parentV] += 1;
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
    vector<node> newEdges;
    int sum = 0;

    makeSet();
    for(int i = 1; i <= M; i++)
    {
        cin >> U >> V >> W;
        sum += W;
        node n;
        n.u = U, n.v = V, n.wt = W;
        newEdges.push_back(n);
    }

    sort(newEdges.begin(), newEdges.end(), myComp);
    vector<pair<int, int>> ans;

    int minCost = 0;
    int maxProfit = 0;
    map<pair<int, int>, int> alreadyChecked;

    for(node n : newEdges)
    {
        pair<int, int> check1 = {n.u, n.v};
        pair<int, int> check2 = {n.v, n.u};
        if(!alreadyChecked[check2] && !alreadyChecked[check2])
        {
            if(findParent(n.u) != findParent(n.v))
            {
                ans.push_back({n.u, n.v});
                minCost += n.wt;
                unionOfEdges(n.u, n.v);
            }
            else
            {
                if(n.wt <= 0)
                    minCost += n.wt;
            }
            alreadyChecked[check1] = 1;
            alreadyChecked[check2] = 1;
        }
        else
        {
            if(n.wt <= 0)
                minCost += n.wt;
        }
        debug(minCost)
    }

    debug(sum)
    cout << sum - minCost;

    return 0;
}

// https://github.com/archishmanghos/Archi-Functions/blob/master/Kruskal-Algorithm.cpp