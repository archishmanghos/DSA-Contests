void dfs(int node, int level, vector<int> &levelCnt, vector<bool> visited, vector<int> graph[]){
    if(visited[node]){
        return;
    }
    
    visited[node] = true;
    levelCnt[level] += 1;
    for(int child : graph[node]){
        dfs(child, (level + 1) % 2, levelCnt, visited, graph);
    }
}
int countOfNodes(vector<int> graph[], int n)
{
    vector<bool> visited(n + 2, false);
    vector<int> levelCnt(2, 0);
    dfs(1, 1, levelCnt, visited, graph);
    int ans = (levelCnt[0] * (levelCnt[0] - 1) / 2) + (levelCnt[1] * (levelCnt[1] - 1) / 2);
    return ans;
}