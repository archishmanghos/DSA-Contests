#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, K, U, V, A[mxN];
vector<int> adj[mxN];

void dfs(int node, vector<int> &leafNodes, vector<bool> &visited)
{
    if(visited[node])
        return;

    visited[node] = true;
    if(adj[node].size() == 1)
    {
        if(visited[adj[node][0]])
            leafNodes.push_back(node);
    }

    for(int child : adj[node])
        dfs(child, leafNodes, visited);
}

void solve()
{
    cin >> N >> K;

    for(int i = 1; i <= K; i++)
        cin >> A[i];
    for(int i = 1; i <= N; i++)
        adj[i].clear();
    for(int i = 1; i <= N - 1; i++)
    {
        cin >> U >> V;
        adj[U].push_back(V);
        adj[V].push_back(U);
    }

    vector<int> leafNodes, distance(N + 2, INF), distanceFromRoot(N + 2, INF);
    vector<bool> visited(N + 2, false);
    dfs(1, leafNodes, visited);

    visited.assign(N + 2, false);
    queue<int> q;
    for(int i = 1; i <= K; i++)
    {
        q.push(A[i]);
        distance[A[i]] = 0;
    }

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        if(visited[node])
            continue;
        visited[node] = true;
        for(int child : adj[node])
        {
            distance[child] = min(distance[child], distance[node] + 1);
            q.push(child);
        }
    }

    visited.assign(N + 2, false);
    q.push(1);
    distanceFromRoot[1] = 0;
    int ans = 0;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        if(visited[node])
            continue;
        visited[node] = true;
        for(int child : adj[node])
        {
            distanceFromRoot[child] = min(distanceFromRoot[child], distanceFromRoot[node] + 1);
            if(distanceFromRoot[child] < distance[child])
                q.push(child);
            else
                ans += 1;
        }
    }

    for(int i = 0; i < leafNodes.size(); i++)
    {
        if(visited[leafNodes[i]])
        {
            cout << -1 << '\n';
            return;
        }
    }

    cout << ans << '\n';
    
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
        solve();

    return 0;
}