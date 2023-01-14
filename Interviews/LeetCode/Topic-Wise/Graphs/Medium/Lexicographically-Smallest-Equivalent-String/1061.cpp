#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    set<int> adj[26];
    int vis[26];
    void dfs (int node, int &ans) {
        if (vis[node]) return;

        ans = min(ans, node);
        vis[node] = 1;
        for (int child : adj[node]) dfs(child, ans);
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for (int i = 0; i < s1.size(); i++) {
            int u = s1[i] - 'a', v = s2[i] - 'a';
            adj[u].insert(v);
            adj[v].insert(u);
        }

        string answer = "";
        for (char c : baseStr) {
            int minimum = c - 'a';
            memset (vis, 0, sizeof(vis));
            dfs ((c - 'a'), minimum);
            answer += (minimum + 'a');
        }

        return answer;
    }
};